#include <opencv_csharp/Conversions.h>
#include <cstring>
#include <opencv2/imgproc.hpp>

namespace OpenCvCSharp
{
	Bitmap^ Conversions::ImageToBitmap(Image^ image)
	{
		if (image->Mat->empty() || (image->Mat->channels() != 1 && image->Mat->channels() != 3))
		{
			return nullptr;
		}

		PixelFormat pixelFormat = PixelFormat::Format8bppIndexed;
		cv::Mat imageToCopy = *image->Mat;
		if (imageToCopy.channels() == 3)
		{
			pixelFormat = PixelFormat::Format24bppRgb;
		}

		Bitmap^ bitmap = gcnew Bitmap(imageToCopy.cols, imageToCopy.rows, pixelFormat);
		BitmapData^ rasterImageBitmapData = bitmap->LockBits(Rectangle(Point::Empty, bitmap->Size), ImageLockMode::ReadWrite, bitmap->PixelFormat);

		size_t numberOfBytesToCopy = imageToCopy.step * imageToCopy.rows;
		size_t numberOfBytesAvailableInBitmap = rasterImageBitmapData->Stride * rasterImageBitmapData->Height;

		if (numberOfBytesToCopy > numberOfBytesAvailableInBitmap)
		{
			return nullptr;
		}

		//Bitmaps have a row stride that is multiple of 4 bytes (padding at the end)
		int matStep = (int)imageToCopy.step;
		if (matStep != rasterImageBitmapData->Stride)
		{
			for (int i = 0; i < imageToCopy.rows; ++i)
			{
				size_t sourceOffset = i * imageToCopy.step;
				size_t destinationOffset = i * rasterImageBitmapData->Stride;
				std::memcpy(((uchar*)rasterImageBitmapData->Scan0.ToPointer()) + destinationOffset, imageToCopy.data + sourceOffset, matStep);
			}
		}
		else
		{
			std::memcpy(rasterImageBitmapData->Scan0.ToPointer(), imageToCopy.data, numberOfBytesToCopy);
		}

		bitmap->UnlockBits(rasterImageBitmapData);

		return bitmap;
	}


	Image^ Conversions::BitmapToImage(Bitmap^ bitmap, BitmapData^ bitmapData)
	{
		Image^ mat = gcnew Image(bitmap->Height, bitmap->Width, Conversions::PixelFormatToOpenCvType(bitmap->PixelFormat), bitmapData->Scan0, bitmapData->Stride, false);
		return mat;
	}

	int Conversions::PixelFormatToOpenCvType(PixelFormat format)
	{
		if (format == PixelFormat::Format8bppIndexed)
		{
			return CV_8UC1;
		}

		if (format == PixelFormat::Format16bppArgb1555 ||
			format == PixelFormat::Format16bppGrayScale ||
			format == PixelFormat::Format16bppRgb555 ||
			format == PixelFormat::Format16bppRgb565)
		{
			return CV_8UC2;
		}

		if (format == PixelFormat::Format24bppRgb)
		{
			return CV_8UC3;
		}

		if (format == PixelFormat::Format32bppArgb ||
			format == PixelFormat::Format32bppPArgb ||
			format == PixelFormat::Format32bppRgb)
		{
			return CV_8UC4;
		}

		return -1;
	}
}
