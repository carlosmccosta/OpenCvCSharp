#pragma once

using namespace System;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;

#include <opencv_csharp/Image.h>

namespace OpenCvCSharp
{
	public ref class Conversions
	{
	public:
		static Bitmap^ ImageToBitmap(Image^ image);
		static Image^ BitmapToImage(Bitmap^ bitmap, BitmapData^ bitmapData);
		static int PixelFormatToOpenCvType(PixelFormat format);
	};
}
