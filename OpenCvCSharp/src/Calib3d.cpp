#include <opencv_csharp/Calib3d.h>

namespace OpenCvCSharp
{
	void Calib3d::CorrectImageDistortion(Image^ image, CameraIntrinsics^ intrinsics)
	{
		cv::Mat imageCorrected;
		cv::undistort(*image->Mat, imageCorrected, *intrinsics->Intrinsics, *intrinsics->DistortionCoefficients, *intrinsics->Intrinsics);
		size_t numberOfBytesToCopy = image->Mat->rows * image->Mat->cols * image->Mat->channels();
		std::memcpy(image->Mat->data, imageCorrected.data, numberOfBytesToCopy);
	}
}
