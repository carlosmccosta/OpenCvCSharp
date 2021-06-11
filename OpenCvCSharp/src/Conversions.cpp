#include <opencv_csharp/Conversions.h>

namespace OpenCvCSharp
{
	Image^ Conversions::BitmapToImage(Bitmap^ bitmap, BitmapData^ bitmapData)
	{
		Image^ mat = gcnew Image(bitmap->Height, bitmap->Width, Conversions::PixelFormatToOpenCvType(bitmap->PixelFormat), bitmapData->Scan0, false);
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
