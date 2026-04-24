#pragma once

using namespace System;
#include <cstring>
#include <opencv2/core.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv_csharp/Image.h>
#include <opencv_csharp/CameraIntrinsics.h>

namespace OpenCvCSharp
{
	public ref class Calib3d
	{
	public:
		static bool CorrectImageDistortion(Image^ image, CameraIntrinsics^ intrinsics);

		Calib3d();

		void InitializeCorrectionOfProjectionImageDistortion(CameraIntrinsics^ intrinsics, int projector_horizontal_resolution, int projector_vertical_resolution);
		bool CorrectProjectionImageDistortion(Image^ image);

	protected:
		cv::Mat* _projectionRectificationMapX;
		cv::Mat* _projectionRectificationMapY;
		bool _correctionOfProjectionImageDistortionInitialized;
	};
}
