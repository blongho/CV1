#include "Base.h"
int main(int argc, char** argv)
{
	
	try
	{
		const std::string muskImg = "../../images/musk.jpg";
		const std::string glassImg = "../../images/sunglass.png";

		// Load the face image and convert to float format
		Mat face = imread(muskImg);
		face.convertTo(face, CV_32FC3);
		face = face / 255.0;

		// Load the sun glass image with alpha channels
		Mat glass = imread(glassImg, -1);
		glass.convertTo(glass, CV_32F);
		glass = glass / 255.0;

		// resize the image to fit over the eye region
		resize(glass, glass, Size(), 0.5, 0.5);

		cout << "Image dimensions(glass) " << glass.size() << endl
			<< "Number of channels(glass) " << glass.channels() << endl;
		
		// Get the height and width of the glasses
		const auto glassHeight = glass.size().height;
		const auto glassWidth = glass.size().width;

		// Separate the Color and alpha channels
		Mat glassRGBAChannels[4];
		Mat glassRGBChannels[3];
		split(glass, glassRGBAChannels);

		for (int i = 0; i < 3; i++) {
			// Copy R,G,B channel from RGBA to RGB
			glassRGBChannels[i] = glassRGBAChannels[i];
		}

		Mat glassBGR, glassMask1;
		// Prepare BGR Image
		merge(glassRGBChannels, 3, glassBGR);
		// Alpha channel is the 4th channel in RGBA Image
		glassMask1 = glassRGBAChannels[3];


		imshow("original face", face);

		//imshow("Sunglass color channels", glassBGR);

		//imshow("Sunglass alpha channels", glassMask1);

		// Replace eye region with glasses
		// By trial an error, the eye region is at (130, 130)
		//  Top left corner of the glasses
		const auto topLeftRow = 130;
		const auto topLeftCol = 130;

		const auto bottomRightRow = topLeftRow + glassHeight;
		const auto bottomRightCol = topLeftCol + glassWidth;

		// Make a copy
		Mat faceWithGlassesNaive = face.clone();
		Mat roiFace = faceWithGlassesNaive(Range(topLeftRow, bottomRightRow), Range(topLeftCol, bottomRightCol));
		// Replace the eye region with the sunglass image
		glassBGR.copyTo(roiFace);

		// display image
		//imshow("Face with glasses", faceWithGlassesNaive);

		/*

		Using Arithmetic Operationsand Alpha Mask
			In order to put the sunglass on top of the eye region, we need to follow these steps :

			1 Create a binary mask with 3 - channels using the single channel mask.
			2 Extract the eye region from the face image
			3 Multiply the Mask with the sunglass to get the masked sunglass
			4 Multiply the negative of Mask with the eye region to create a hole in the eye region for the sunglass to be placed.
			5 Add the masked sun
			6 Replace the eye region in the original image with that of the output we got in the previous step. This is the final output
		*/

		// Make the dimensions of the mask same as the input image.
	// Since Face Image is a 3-channel image, we create a 3 channel image for the mask
		Mat glassMask;
		Mat glassMaskChannels[] = { glassMask1,glassMask1,glassMask1 };
		merge(glassMaskChannels, 3, glassMask);

		// Make a copy
		Mat faceWithGlassesArithmetic = face.clone();

		// Get the eye region from the face image
		Mat eyeROI = faceWithGlassesArithmetic(Range(topLeftRow, bottomRightRow), Range(topLeftCol, bottomRightCol));

		Mat eyeROIChannels[3];
		split(eyeROI, eyeROIChannels);
		Mat maskedEyeChannels[3];
		Mat maskedEye;

		for (int i = 0; i < 3; i++)
		{
			// Use the mask to create the masked eye region
			multiply(eyeROIChannels[i], (1 - glassMaskChannels[i]), maskedEyeChannels[i]);
		}

		merge(maskedEyeChannels, 3, maskedEye);

		Mat maskedGlass;
		// Use the mask to create the masked sunglass region
		multiply(glassBGR, glassMask, maskedGlass);

		Mat eyeRoiFinal;
		
		// Combine the Sunglass in the Eye Region to get the augmented image
		add(maskedEye, maskedGlass, eyeRoiFinal);

		//imshow("Masked Eye region", maskedEye);
		//imshow("Masked Sun glass region", maskedGlass);
		//imshow("Augmented Eye and Sunglass", eyeRoiFinal);

		const float alpha = 1;
		const int beta = -255;
		// Replace the eye ROI with the output from the previous section
		eyeRoiFinal.copyTo(eyeROI);

		
		imshow("Face with sunglasses", faceWithGlassesArithmetic);
	}

	catch (const std::exception & e)
	{
		cerr << "Error " << e.what() << endl;
	}
	



	const auto key = waitKey(0);
	cout << "Key pressed is : ascii value = " << key << ", printable: " << static_cast<char>(key) << endl;

	return 0;
}
