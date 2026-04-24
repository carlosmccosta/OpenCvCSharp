#include <opencv_csharp/Image.h>

namespace OpenCvCSharp
{
	Image::Image(int height, int width, int type, IntPtr data, int rowStride, bool freeMatDataOnDestructor)
	{
		_mat = new cv::Mat(height, width, type, data.ToPointer(), (size_t)rowStride);
		_freeMatDataOnDestructor = freeMatDataOnDestructor;
	}


	Image::~Image()
	{
		this->!Image();
	}


	Image::!Image()
	{
		if (_mat != nullptr)
		{
			if (!_freeMatDataOnDestructor)
			{
				_mat->data = nullptr;
				_mat->rows = 0;
				_mat->cols = 0;
			}
			delete _mat;
			_mat = nullptr;
		}
	}


	bool Image::copyDataFromOtherImage(cv::Mat other_image)
	{
		size_t numberOfBytesToCopy = other_image.step * other_image.rows;
		size_t numberOfBytesAvailable = Mat->step * Mat->rows;

		if (numberOfBytesToCopy <= numberOfBytesAvailable)
		{
			if (Mat->step != other_image.step)
			{
				for (int i = 0; i < other_image.rows; ++i)
				{
					size_t sourceOffset = i * other_image.step;
					size_t destinationOffset = i * Mat->step;
					std::memcpy(Mat->data + destinationOffset, other_image.data + sourceOffset, other_image.step);
				}
			}
			else
			{
				std::memcpy(Mat->data, other_image.data, numberOfBytesToCopy);
			}

			return true;
		}

		return false;
	}
}
