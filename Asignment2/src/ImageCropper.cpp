#include "ImageCropper.h"

ImageCropper::ImageCropper(Mat& image)
	:source{ image }, center{ 0,0 }{
	std::cout << "Image gotten is " << image.size() << std::endl;
}

void ImageCropper::drawBoundingBox(int action, int x, int y, int flags, void* userdata)
{

	if (action == EVENT_LBUTTONDOWN) {
		center = Point(x, y);
		circle(source, center, 1, Scalar(250, 250, 0), 2, LINE_AA);
	}
	else if (action == EVENT_LBUTTONUP) {

	}
}

void ImageCropper::saveImage()
{
}

