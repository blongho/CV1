#include "Base.h"
int main()
{
	
	try
	{
		const std::string path = "../../images/messi5.jpg";
		Mat image = imread(path);
		const double scalingFactor = 1 / 255.0;
		const double shift = 0;
		Mat contrastHigh = image.clone();

		imshow("Origingal image ", image);
		imageInfo(image);
		//Converting from unsigned char to float(32bit)
		image.convertTo(image, CV_32FC3, scalingFactor, shift);
		imshow("Converted image", image);
		imageInfo(image);
		//Converting from float to unsigned char
		image.convertTo(image, CV_8UC3, 1.0 / scalingFactor, shift);
		imageInfo(image);
		imshow("Restored image", image);


		// Changing the contrast
		const double contrastPercentage = 30;
		// Multiply with scaling factor to increase contrast
		// Convert contrastHigh to float
		contrastHigh.convertTo(contrastHigh, CV_64F);
		contrastHigh = contrastHigh * (1 + contrastPercentage / 100.0);

		imshow("Improved contrast ", contrastHigh);
		imageInfo(contrastHigh);
	}
	catch (const std::exception & e)
	{
		cerr << "Error " << e.what() << endl;
	}
	



	const auto key = waitKey(0);
	cout << "Key pressed is : ascii value = " << key << ", printable: " << static_cast<char>(key) << endl;

	return 0;
}
