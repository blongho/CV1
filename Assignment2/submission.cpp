/**
 @file	Assignment2\submission.cpp.

 @brief	Implements the task for submission 2. 

	The cropped image will be saved in the images directory as 
	images/cropped.jpg


 @author	Bernard Che Longho
 @date		2020-08-21
 */

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>

/** @brief	The image */
cv::Mat img;
/** @brief	The top left */
cv::Point topLeft;
/** @brief	The end point */
cv::Point endPoint;
/** @brief	The rectangle box */
cv::Rect box;
/** @brief	Relative path to all image files */
const std::string IMAGE_PATH = "../images/";
/** @brief	The name of the Window*/
const std::string window = "image";
/** @brief	Green color */
const cv::Scalar green = cv::Scalar(0, 255, 0);
/** @brief	Blue color */
const cv::Scalar blue = cv::Scalar(255, 0, 0);

/**
 @fn	void cropAndSaveImage(int event, int x, int y, int flags, void* userdata);

 @brief	Crop and save image

 @param 			event   	The event.
 @param 			x			The x coordinate.
 @param 			y			The y coordinate.
 @param 			flags   	The flags.
 @param [in,out]	userdata	If non-null, the userdata.
 */

void cropAndSaveImage(int event, int x, int y, int flags, void* userdata);

/**
 @fn	int main()

 @brief	Main entry-point for this application

 @date	2020-08-21

 @returns	Exit-code for the process - 0 for success, else an error code.
 */

int main()
{
	try
	{
		const std::string imagePath = IMAGE_PATH + "boy.jpg";

		// read the source image
		img = cv::imread(imagePath);

		// Instructions
		putText(img, "Choose top left corner and drag", cv::Point(10, 30), cv::FONT_HERSHEY_SIMPLEX, 0.7, cv::Scalar(255, 255, 255), 2);
		
		// show the image
		cv::imshow(window, img);

		// Listen for mouse events
		cv::setMouseCallback(window, cropAndSaveImage);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error " << e.what() << std::endl;
	}


	const auto key = cv::waitKey(0);
	std::cout << "Key pressed is : ascii value = " << key << ", printable: " << static_cast<char>(key) << std::endl;
	cv::destroyAllWindows();
	return 0;
}



void cropAndSaveImage(int event, int x, int y, int flags, void* userdata) {
	// Action to be taken when left mouse button is pressed
	const cv::Point tmp = cv::Point(x, y);
	if (event == cv::EVENT_LBUTTONDOWN)
	{
		topLeft = tmp;
		// Mark the top left corner
		cv::circle(img, topLeft, 1, green, 2, cv::LINE_AA);
	}
	// Action to be taken when left mouse button is released
	else if (event == cv::EVENT_LBUTTONUP)
	{
		endPoint = tmp;
		// Draw a rectangle
		cv::rectangle(img, topLeft, endPoint, blue, 2);
		box.width = cv::abs(topLeft.x - endPoint.x);
		box.height = cv::abs(topLeft.y - endPoint.y);
		box.x = cv::min(topLeft.x, endPoint.x);
		box.y = cv::min(topLeft.y, endPoint.y);
		cv::Mat cropped(img, box); //Selecting a ROI(region of interest) from the original pic
		cv::imwrite(IMAGE_PATH + "cropped.jpg", cropped);
		imshow(window, img);
	}
}
