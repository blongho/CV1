#include "Base.h"
int main(int argc, char** argv)
{
	
	try
	{
		const std::string imagePath = "../../images/boy.jpg";

		Mat image = imread(imagePath);

		imshow("A boy", image);

		Mat imageLine = image.clone();

		line(imageLine, Point(200, 80), Point(280, 80), Scalar(0, 255, 0), 3, LINE_AA);
		
		imshow("Boy with score", imageLine);
	
	}

	catch (const std::exception & e)
	{
		cerr << "Error " << e.what() << endl;
	}
	



	const auto key = waitKey(0);
	cout << "Key pressed is : ascii value = " << key << ", printable: " << static_cast<char>(key) << endl;

	return 0;
}
