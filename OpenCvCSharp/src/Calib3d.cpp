#include <opencv_csharp/Calib3d.h>

namespace OpenCvCSharp
{
	bool Calib3d::CorrectImageDistortion(Image^ image, CameraIntrinsics^ intrinsics)
	{
		cv::Mat imageCorrected;
		cv::undistort(*image->Mat, imageCorrected, *intrinsics->Intrinsics, *intrinsics->DistortionCoefficients, *intrinsics->Intrinsics);

		size_t numberOfBytesToCopy = imageCorrected.step * imageCorrected.rows;
		size_t numberOfBytesAvailable = image->Mat->step * image->Mat->rows;

		if (numberOfBytesToCopy <= numberOfBytesAvailable)
		{
			if (image->Mat->step != imageCorrected.step)
			{
				for (int i = 0; i < imageCorrected.rows; ++i)
				{
					size_t sourceOffset = i * imageCorrected.step;
					size_t destinationOffset = i * image->Mat->step;
					std::memcpy(image->Mat->data + destinationOffset, imageCorrected.data + sourceOffset, imageCorrected.step);
				}
			}
			else
			{
				std::memcpy(image->Mat->data, imageCorrected.data, numberOfBytesToCopy);
			}

			return true;
		}

		return false;
	}
}
