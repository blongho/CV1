#ifndef IMAGE_CROPPER_H
#define IMAGE_CROPPER_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace cv;
const std::string IMAGE_PATH = "../images/";
class ImageCropper
{
private:
	Mat source;
	Point center;

public:
	ImageCropper() = delete; // prevent instantiation of this class without a Mat
	ImageCropper(Mat& image);

	void drawBoundingBox(int action, int x, int y, int flags, void* userdata);
	void saveImage();

};

#endif // !IMAGE_CROPPER_H


