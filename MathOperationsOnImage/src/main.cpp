#include "Base.h"
#include "ContrastAndBrightness.h"
int main(int argc, char** argv)
{
	
	try
	{
		const std::string path = "../../images/messi5.jpg";
		//Mat image = imread(path);
		//const double scalingFactor = 1 / 255.0;
		//const double shift = 0;
		//Mat contrastHigh = image.clone();
		//Mat bright = image.clone();

		////imshow("Origingal image ", image);
		////imageInfo(image);
		////Converting from unsigned char to float(32bit)
		//image.convertTo(image, CV_32FC3, scalingFactor, shift);
		////imshow("Converted image", image);
		////imageInfo(image);
		////Converting from float to unsigned char
		//image.convertTo(image, CV_8UC3, 1.0 / scalingFactor, shift);
		////imageInfo(image);
		////imshow("Restored image", image);


		//// Changing the contrast
		//const double contrastPercentage = 30;
		//// Multiply with scaling factor to increase contrast
		//// Convert contrastHigh to float
		//contrastHigh.convertTo(contrastHigh, CV_64F);
		//contrastHigh = contrastHigh * (1 + contrastPercentage / 100.0);

		////imshow("Improved contrast ", contrastHigh);
		////imageInfo(contrastHigh);

		//// Altering the brightness simply implies adding/subtracting some offset value to/from the RGB values
		//const int brightnessOffset = 30;
		//Mat brightHigh = image.clone();
		//Mat brightHighChannels[3];
		//split(brightHigh, brightHighChannels);

		//for (int i = 0; i < 3; i++) {
		//	add(brightHighChannels[i], brightnessOffset, brightHighChannels[i]);
		//}

		//merge(brightHighChannels, 3, brightHigh);

		////imshow("Original Image", image);
		////imshow("Brightened Image", brightHigh);
		////imshow("Constract Image", contrastHigh);
		//double minVal, maxVal;
		//cout << "Original Image Datatype : " << type2str(image.type()) << endl;
		//cout << "Contrast Image Datatype : " << type2str(contrastHigh.type()) << endl;
		//cout << "Brightness Image Datatype : " << type2str(brightHigh.type()) << endl;

		//minMaxLoc(image, &minVal, &maxVal);
		//cout << "Original Image Highest Pixel Intensity : " << maxVal << endl;
		//minMaxLoc(contrastHigh, &minVal, &maxVal);
		//cout << "Contrast Image Highest Pixel Intensity : " << maxVal << endl;
		//minMaxLoc(brightHigh, &minVal, &maxVal);
		////cout << "Brightness Image Highest Pixel Intensity : " << maxVal << endl;
		//printOn("Brightness Image Highest Pixel Intensity", maxVal);
		//printOn("This is a long combination of values", 24.6, 'j', 4);

		//uint8_t data[] = { 100,110,120,130 };
		//Mat a(2, 2, CV_8UC1, data);
		//printOn(a);
		//const uint8_t scalar{ 130 };
		//printOn(a + scalar);
		//printOn(a - scalar);
		//Mat addition;
		//add(a, Scalar(130), addition);
		//printOn(addition);

		//int dataInt[] = { 100,110,120,130 };
		//Mat b(2, 2, CV_32SC1, dataInt);
		//b = b + 130;
		//printOn("Corrected", b);
		//b.convertTo(b, CV_8UC1);
		//printOn("Converted back to originala", b);

		///*
		//It is a good practice to convert the uint8 to float and normalize the range to [0,1] 
		//and change it back to [0,255] after doing all arithmetic operations
		//*/
		//Mat a_float32;
		//a.convertTo(a_float32, CV_32F, 1.0 / 255.0, 0);
		//a_float32 = a_float32 + 130.0 / 255.0;
		//printOn("Convert float", a_float32);

		//Mat c;
		//a_float32.convertTo(c, CV_32F, 255.0, 0.0);
		//cout << c;

		//// Clipped output
		//Mat b_uint8;
		//c.convertTo(b_uint8, CV_8UC1);
		//cout << b_uint8;
		

		Mat image = imread(path);
		transform(image);

		gammaCorrection(image, -10.0f);
	}

	catch (const std::exception & e)
	{
		cerr << "Error " << e.what() << endl;
	}
	



	const auto key = waitKey(0);
	cout << "Key pressed is : ascii value = " << key << ", printable: " << static_cast<char>(key) << endl;

	return 0;
}
