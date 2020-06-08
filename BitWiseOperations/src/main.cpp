#include "Base.h"

int main(int argc, char** argv)
{
	
	try
	{
		const std::string muskImg = "../../images/musk.jpg";
		const std::string glassImg = "../../images/sunglass.png";

		// Load the images
		Mat faceImage = imread(muskImg);

		// Make a copy of this
		Mat faceWithGlassBitwise = faceImage.clone();

		// Load the sunglasses with alpha channels
		Mat glassPNG = imread(glassImg, -1);
		cout << "Image dimensions before resize " << glassPNG.size() << endl;

		// Resize the image to fit over the eye regieion
		resize(glassPNG,glassPNG, Size(), 0.5, 0.5);

		cout << "Image dimensions after resize " << glassPNG.size() << endl;

		const int glassHt = glassPNG.size().height;
		const int glassWt = glassPNG.size().width;

		// Separate the color and alpha channels
		Mat glassRGBAChannels[4];
		Mat glassRGBChannels[3];

		split(glassPNG, glassRGBAChannels);

		for (int i = 0; i < 3; i++) {
			// copy RGB channels from RGBA to RGB
			glassRGBChannels[i] = glassRGBAChannels[i];
		}

		Mat glassBGR, glassMask1;
		// Prepare BGR image
		merge(glassRGBChannels, 3, glassBGR);

		// Alpha channel is the 4th channel in RGBA Image
		glassMask1 = glassRGBAChannels[3];

		// imshow("Original image", faceImage);

		// imshow("GlassRGB", glassBGR);

		// imshow("glassMask", glassMask1);
		
		// Get the masked output
		const int topLeftRow = 130;
		const int topLeftCol = 130;
		const int bottomRightRow = topLeftRow + glassHt;
		const int bottomRightCol = topLeftCol + glassWt;

		// Get the eye region from the face image
		Mat eyeROI = faceWithGlassBitwise(Range(topLeftRow, bottomRightRow), Range(topLeftCol, bottomRightCol));

		// Make the dimensions of the mask same as the input image
		//´Since faceImage is a 3-channel image, we create a 3 channel image for the mask
		Mat glassMask;
		Mat glassMaskChannels[] = { glassMask1, glassMask1, glassMask1 };

		merge(glassMaskChannels, 3, glassMask);

		// use the mask to create the masked eye region
		Mat eye;
		Mat glassMaskNOT;
		bitwise_not(glassMask1, glassMaskNOT);

		Mat eyeChannels[3];
		Mat eyeROIChannels[3];
		Mat maskedGlass;
		Mat eyeROIfinal;
		split(eyeROI, eyeROIChannels);

		for (int i = 0; i < 3; i++) {
			bitwise_and(eyeROIChannels[i], glassMaskNOT, eyeChannels[i]);
		}

		merge(eyeChannels, 3, eye);

		Mat glassMaskNOTChannels[] = { glassMaskNOT, glassMaskNOT, glassMaskNOT };
		Mat glassMaskNOTMerged;

		merge(glassMaskNOTChannels, 3, glassMaskNOTMerged);
		bitwise_and(eyeROI, glassMaskNOTMerged, eye);

		// Use the mask to create the masked sunglass region
		Mat sunglass;
		Mat sunglassChannels[3];
		Mat glassBGRChannels[3];

		split(glassBGR, glassBGRChannels);

		for (int i = 0; i < 3; i++) {
			bitwise_and(glassBGRChannels[i], glassMask1, sunglassChannels[i]);
		}

		merge(sunglassChannels, 3, sunglass);

		multiply(glassBGR, glassMask, maskedGlass);

		// Combine the sunglass in the eye region to get the augmented image
		bitwise_or(eye, sunglass, eyeROIfinal);


		imshow("Eye", eye);
		imshow("sunglass", sunglass);
		imshow("finalRoi", eyeROIfinal);

		// Replace the eye ROI with the output from the previous section
		eyeROIfinal.copyTo(eyeROI);
		imshow("Modified image", faceWithGlassBitwise);
	}

	catch (const std::exception & e)
	{
		cerr << "Error " << e.what() << endl;
	}
	



	const auto key = waitKey(0);
	cout << "Key pressed is : ascii value = " << key << ", printable: " << static_cast<char>(key) << endl;

	return 0;
}
