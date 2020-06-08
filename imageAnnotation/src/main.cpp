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
	
		// Drawing a circle in an image
		
		Mat imageCircle;
		image.copyTo(imageCircle);

		circle(imageCircle, Point{ 250, 125 }, 100, Scalar{ 255, 0, 0 }, 5, LINE_AA);

		imshow("Boy with circle", imageCircle);

		Mat filledHead;
		image.copyTo(filledHead);

		// Specifying the thickness to -1 fills the circle
		circle(filledHead, Point{ 250, 125 }, 100, Scalar{ 0, 0, 255 }, -1, LINE_AA);

		imshow("Boy with filled circle", filledHead);
	}

	catch (const std::exception & e)
	{
		cerr << "Error " << e.what() << endl;
	}
	



	const auto key = waitKey(0);
	cout << "Key pressed is : ascii value = " << key << ", printable: " << static_cast<char>(key) << endl;

	return 0;
}
