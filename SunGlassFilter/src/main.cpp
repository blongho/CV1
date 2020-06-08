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

		imshow("Sunglass color channels", glassBGR);

		imshow("Sunglass alpha channels", glassMask1);

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
		imshow("Face with glasses", faceWithGlassesNaive);
	}

	catch (const std::exception & e)
	{
		cerr << "Error " << e.what() << endl;
	}
	



	const auto key = waitKey(0);
	cout << "Key pressed is : ascii value = " << key << ", printable: " << static_cast<char>(key) << endl;

	return 0;
}
