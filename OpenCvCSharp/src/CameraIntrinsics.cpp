#include <opencv_csharp/CameraIntrinsics.h>

namespace OpenCvCSharp
{
	CameraIntrinsics::CameraIntrinsics(
		double focalLengthX, double focalLengthY,
		double principalPointX, double principalPointY,
		double axisSkew,
		double radialDistortionK1, double radialDistortionK2, double radialDistortionK3,
		double tangentialDistortionP1, double tangentialDistortionP2)
	{
		_intrinsics = new cv::Mat(3, 3, CV_64F, 0.0);
		_intrinsics->at<double>(2, 2) = 1.0;
		_distortionCoefficients = new cv::Mat(5, 1, CV_64F, 0.0);

		FocalLengthX = focalLengthX;
		FocalLengthY = focalLengthY;
		PrincipalPointX = principalPointX;
		PrincipalPointY = principalPointY;
		AxisSkew = axisSkew;
		RadialDistortionK1 = radialDistortionK1;
		RadialDistortionK2 = radialDistortionK2;
		RadialDistortionK3 = radialDistortionK3;
		TangentialDistortionP1 = tangentialDistortionP1;
		TangentialDistortionP2 = tangentialDistortionP2;
	}


	CameraIntrinsics::~CameraIntrinsics()
	{
		this->!CameraIntrinsics();
	}


	CameraIntrinsics::!CameraIntrinsics()
	{
		if (_intrinsics != nullptr)
		{
			delete _intrinsics;
			_intrinsics = nullptr;
		}

		if (_distortionCoefficients != nullptr)
		{
			delete _distortionCoefficients;
			_distortionCoefficients = nullptr;
		}
	}
}
