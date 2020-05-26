#include "Base.h"
int main()
{
	/*
	1. Creating an image
	 We use Mat(height, width, datatypeOfTheMatrix,
   */
	try
	{
		const auto height = 200;
		const auto width = 400;
		Mat emptyMatrix = Mat(height, width, CV_8UC3, Scalar(0, 0, 0));

		// An 8 bit per color image, unsigned integers (0 - 255) with three channels
		// The pixels can take any value from 0 to 255. We set all the pixels to 0(black)
		//imshow("Empty Image before ",emptyMatrix);

		// Change the image pixels from black to white
		emptyMatrix.setTo(Scalar(255, 255, 255));

		//imshow("Empty Image after set to white ", emptyMatrix);


		// Create an empty matrix of the same size as the original image

		Mat emptyFromAnother = Mat(emptyMatrix.size(), emptyMatrix.type(), Scalar(100, 100, 100));

		//imshow("Copied from original", emptyFromAnother);


		//2. Cropping an image
		// We need to know where to crop i.e. the range of the rows and columns of interest

		const std::string path = "../../images/messi5.jpg";

		Mat original = imread(path, -1);
		cout << "Size of apple " << original.size() << endl; // [548 x 342]
		imshow("Original apple", original);

		// Crop using some random values
		// x coordinates = 170 to 320
		// y coordinates = 40 to 200
		Mat croppedApple = original(Range(40, 200), Range(170, 320));
		//imshow("Cropped Apple", croppedApple);

	// 3. Copying a region of an image to another 
	// Worth noting is the fact that the size of the rectangle that you cropped
	// is same as the area to paste it

		// Create a copy of the original image, hand
		Mat copiedImage = original.clone();
		//  imshow("Copied apple ", copiedImage);

	  // Get roi
		Mat copyRoi = copiedImage(Range(40, 200), Range(180, 320));

		// Find height and width of the ROI
		const auto roiHeight = copyRoi.size().height;
		const auto roiWidth = copyRoi.size().width;

		// Copy to left of Face
		copyRoi.copyTo(copiedImage(Range(40, 40 + roiHeight), Range(10, 10 + roiWidth)));
		// Copy to right of Face
		copyRoi.copyTo(copiedImage(Range(40, 40 + roiHeight), Range(330, 330 + roiWidth)));

		//imshow("Output image ", copiedImage);

		// Resizing an image
		// cv::resize
	   /*

	   Function Syntax
			void cv::resize (   InputArray  src,
			OutputArray     dst,
			Size    dsize,
			double  fx = 0,
			double  fy = 0,
			int     interpolation = INTER_LINEAR
			)
			Parameters

			src - input image
			dst - output resized image
			dsize - output image size
			fx - scale factor along the horizontal axis;
			fy - scale factor along the vertical axis; Either dsize or both fx and fy must be non-zero.
			interpolation - interpolation method ( Bilinear / Bicubic etc ).

			There are two ways of using the resize function.

			Specify width and height of output image explicitly
			Use the dsize argument to specify the output size in the form (width,height).

			Specify the scaling factors for resizing ( for both width and height )

			Use fx and fy arguments to specify the scaling factor for horizontal and vertical axis respectively. It should be a float.

			The output size is calculated as: Size(round(fx*src.cols), round(fy*src.rows))
	   */

	   // Resizing image with explicit specification of sizes
	   //  original dimens [548 x 342]

		const auto resizedWidth = 548 / 2;
		const auto resizedHeight = 342 / 2;
		Mat resizedDown;
		resize(original, resizedDown, Size(resizedWidth, resizedHeight), INTER_LINEAR);

		const auto resizedWidthUp = 548 * 2;
		const auto resizedHeightUp = 342 * 2;

		Mat resizeUp;
		resize(original, resizeUp, Size(resizedWidthUp, resizedHeightUp), INTER_LINEAR);

		//imshow("Scaled down", resizedDown);
		//imshow("Scaled up", resizeUp);

		// Scaling using scaling factor
		const auto scalupX{ 1.5 };
		const auto scalupY{ 1.5 };

		const auto scaleDownFactor = 0.6;

		Mat scaledUp, scaledDown;
		resize(original, scaledDown, Size(), scaleDownFactor, scaleDownFactor, INTER_LINEAR);
		resize(original, scaledUp, Size(), scalupX, scalupY, INTER_LINEAR);

		imshow("new up", scaledUp);
		imshow("new down", scaledDown);

	}
	catch (const std::exception & e)
	{
		cerr << "Error " << e.what() << endl;
	}
	catch (const cv::Exception & cve) {
		cerr << "Error " << cve.what() << endl;
	}



	const auto key = waitKey(0);
	cout << "Key pressed is : ascii value = " << key << ", printable: " << static_cast<char>(key) << endl;

	return 0;
}
