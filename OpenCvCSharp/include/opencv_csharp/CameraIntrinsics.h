#pragma once

using namespace System;
#include <opencv2/core.hpp>

namespace OpenCvCSharp
{
	public ref class CameraIntrinsics
	{
	public:
		CameraIntrinsics(
			double focalLengthX, double focalLengthY,
			double principalPointX, double principalPointY,
			double axisSkew,
			double radialDistortionK1, double radialDistortionK2, double radialDistortionK3,
			double tangentialDistortionP1, double tangentialDistortionP2);

		~CameraIntrinsics();
		!CameraIntrinsics();


		property cv::Mat* Intrinsics
		{
			cv::Mat* get() { return _intrinsics; }
		}


		property cv::Mat* DistortionCoefficients
		{
			cv::Mat* get() { return _distortionCoefficients; }
		}


		property double FocalLengthX
		{
			double get() { return _intrinsics->at<double>(0, 0); }
			void set(double value) { _intrinsics->at<double>(0, 0) = value; }
		}


		property double FocalLengthY
		{
			double get() { return _intrinsics->at<double>(1, 1); }
			void set(double value) { _intrinsics->at<double>(1, 1) = value; }
		}


		property double PrincipalPointX
		{
			double get() { return _intrinsics->at<double>(0, 2); }
			void set(double value) { _intrinsics->at<double>(0, 2) = value; }
		}


		property double PrincipalPointY
		{
			double get() { return _intrinsics->at<double>(1, 2); }
			void set(double value) { _intrinsics->at<double>(1, 2) = value; }
		}

		property double AxisSkew
		{
			double get() { return _intrinsics->at<double>(0, 1); }
			void set(double value) { _intrinsics->at<double>(0, 1) = value; }
		}


		property double RadialDistortionK1
		{
			double get() { return _distortionCoefficients->at<double>(0); }
			void set(double value) { _distortionCoefficients->at<double>(0) = value; }
		}


		property double RadialDistortionK2
		{
			double get() { return _distortionCoefficients->at<double>(1); }
			void set(double value) { _distortionCoefficients->at<double>(1) = value; }
		}


		property double RadialDistortionK3
		{
			double get() { return _distortionCoefficients->at<double>(4); }
			void set(double value) { _distortionCoefficients->at<double>(4) = value; }
		}


		property double TangentialDistortionP1
		{
			double get() { return _distortionCoefficients->at<double>(2); }
			void set(double value) { _distortionCoefficients->at<double>(2) = value; }
		}


		property double TangentialDistortionP2
		{
			double get() { return _distortionCoefficients->at<double>(3); }
			void set(double value) { _distortionCoefficients->at<double>(3) = value; }
		}

	protected:
		cv::Mat* _intrinsics;
		cv::Mat* _distortionCoefficients;
	};
}
