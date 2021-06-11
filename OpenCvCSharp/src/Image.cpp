#include <opencv_csharp/Image.h>

namespace OpenCvCSharp
{
	Image::Image(int height, int width, int type, IntPtr data, bool freeMatDataOnDestructor)
	{
		_mat = new cv::Mat(height, width, type, data.ToPointer());
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
}
