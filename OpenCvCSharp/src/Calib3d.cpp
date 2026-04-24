#include <opencv2/imgproc.hpp>
#include <opencv_csharp/Calib3d.h>

namespace OpenCvCSharp
{
	bool Calib3d::CorrectImageDistortion(Image^ image, CameraIntrinsics^ intrinsics)
	{
		cv::Mat imageCorrected;
		cv::undistort(*image->Mat, imageCorrected, *intrinsics->Intrinsics, *intrinsics->DistortionCoefficients, *intrinsics->Intrinsics);

		return image->copyDataFromOtherImage(imageCorrected);
	}


	Calib3d::Calib3d()
	{
		_correctionOfProjectionImageDistortionInitialized = false;
	}

	void Calib3d::InitializeCorrectionOfProjectionImageDistortion(CameraIntrinsics^ intrinsics, int projector_horizontal_resolution, int projector_vertical_resolution)
	{
		_projectionRectificationMapX = new cv::Mat();
		_projectionRectificationMapY = new cv::Mat();

		cv::initInverseRectificationMap(
			*intrinsics->Intrinsics,
			*intrinsics->DistortionCoefficients,
			cv::Mat_<double>::eye(3, 3),
			*intrinsics->Intrinsics,
			cv::Size(projector_horizontal_resolution, projector_vertical_resolution),
			CV_32FC1,
			*_projectionRectificationMapX,
			*_projectionRectificationMapY
		);

		_correctionOfProjectionImageDistortionInitialized = true;
	}


	bool Calib3d::CorrectProjectionImageDistortion(Image^ image)
	{
		if (_correctionOfProjectionImageDistortionInitialized)
		{
			cv::Mat imageCorrected;
			cv::remap(*image->Mat, imageCorrected, *_projectionRectificationMapX, *_projectionRectificationMapY, cv::INTER_LINEAR);

			return image->copyDataFromOtherImage(imageCorrected);
		}
		
		return false;
		
	}
}
