#pragma once

using namespace System;
#include <opencv2/core.hpp>

namespace OpenCvCSharp
{
	public ref class Image
	{
	public:
		Image(int height, int width, int type, IntPtr data, bool freeMatDataOnDestructor);
		~Image();
		!Image();

		property int Width
		{
			int get() { return _mat->cols; }
			void set(int value) { _mat->cols = value; }
		}


		property int Height
		{
			int get() { return _mat->rows; }
			void set(int value) { _mat->rows = value; }
		}


		property int Type
		{
			int get() { return _mat->type(); }
		}


		property IntPtr Data
		{
			IntPtr get() { return (IntPtr)_mat->data; }
			void set(IntPtr value) { _mat->data = (uchar*)value.ToPointer(); }
		}

		property cv::Mat* Mat
		{
			cv::Mat* get() { return _mat; }
		}

		property bool FreeMatDataOnDestructor
		{
			bool get() { return _freeMatDataOnDestructor; }
			void set(bool value) { _freeMatDataOnDestructor = value; }
		}

	protected:
		cv::Mat* _mat;
		bool _freeMatDataOnDestructor;
	};
}
