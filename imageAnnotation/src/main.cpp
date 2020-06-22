#include "Base.h"
int main(int argc, char** argv)
{
	
	try
	{
		const std::string imagePath = "../../images/boy.jpg";

		Mat image = imread(imagePath);

		//imshow("A boy", image);

		Mat imageLine = image.clone();

		line(imageLine, Point(200, 80), Point(280, 80), Scalar(0, 255, 0), 3, LINE_AA);
		
		//imshow("Boy with score", imageLine);
	
		// Drawing a circle in an image
		
		Mat imageCircle;
		image.copyTo(imageCircle);

		circle(imageCircle, Point{ 250, 125 }, 100, Scalar{ 255, 0, 0 }, 5, LINE_AA);

		//imshow("Boy with circle", imageCircle);

		Mat filledHead;
		image.copyTo(filledHead);

		// Specifying the thickness to -1 fills the circle
		//circle(filledHead, Point{ 250, 125 }, 100, Scalar{ 0, 0, 255 }, -1, LINE_AA);

		//imshow("Boy with filled circle", filledHead);

		// Drawing an ellipse
		
		Mat imageEllipse;
		image.copyTo(imageEllipse);

		ellipse(imageEllipse, Point(250, 125), Point(100, 50), 0, 0, 360, Scalar(255, 0, 0), 3, LINE_AA);

		ellipse(imageEllipse, Point(250, 125), Point(100, 50), 90, 0, 360, Scalar(0, 0, 255), 3, LINE_AA);

		// draw half ellipse
		ellipse(imageEllipse, Point(250, 125), Point(100, 50), 0, 180, 360, Scalar(0, 255, 0), -3, LINE_AA);
		//imshow("Image with ellipse", imageEllipse);

		// Drawing a rectangle
		
		Mat imageRect;
		image.copyTo(imageRect);
		rectangle(imageRect, Point(170, 50), Point(300, 200), Scalar(255, 0, 255), 5, LINE_AA);

		//imshow("image with rectangle", imageRect);
		
		// Adding text to an image
		Mat imageWithText;
		image.copyTo(imageWithText);

		const auto text = "OpenCV is cool";
		const auto fontScale = 1.5;
		const auto fontFace = cv::HersheyFonts::FONT_HERSHEY_COMPLEX;
		const auto fontColor = Scalar(250, 10, 10);
		const auto fontThickness = 2;
		putText(imageWithText, text, Point(20, 350), fontFace, fontScale, fontColor, fontThickness, LINE_AA);

		imshow("Image with text", imageWithText);

		// Get the fontScale given the height and font
		const auto pixelHeight = 20;
		const auto scaledFont = getFontScaleFromHeight(fontFace, pixelHeight, fontThickness);
		cout << "Font scale " << scaledFont << ", before scaling, it was " << fontScale << endl;

		const auto imageWithScaledFont = image.clone();

		putText(imageWithScaledFont, text, Point(20, 350), fontFace, scaledFont, fontColor, fontThickness, LINE_AA);

		imshow("Image with scaled font", imageWithScaledFont);


		// Automatically get the size of the text
		Mat imageGetTextSize;
		imageGetTextSize = image.clone();
		int imageHeight = imageGetTextSize.rows;
		int imageWidth = imageGetTextSize.cols;

		// Get the text box height and width and also the baseLine
		int baseLine = 0;
		Size textSize = getTextSize(text, fontFace, fontScale, fontThickness, &baseLine);

		int textWidth = textSize.width;
		int textHeight = textSize.height;

		cout << "TextWidth = " << textWidth << ", TextHeight = " << textHeight << ", baseLine = " << baseLine;
		// Get the coordinates of text box bottom left corner
	// The xccordinate will be such that the text is centered
		int xcoordinate = (imageWidth - textWidth) / 2;
		// The y coordinate will be such that the entire box is just 10 pixels above the bottom of image
		int ycoordinate = (imageHeight - baseLine - 10);

		cout << "TextBox Bottom Left = (" << xcoordinate << "," << ycoordinate << ")";
		// Draw the Canvas using a filled rectangle
		Scalar canvasColor = Scalar(255, 255, 255);
		Point canvasBottomLeft(xcoordinate, ycoordinate + baseLine);
		Point canvasTopRight(xcoordinate + textWidth, ycoordinate - textHeight);

		rectangle(imageGetTextSize, canvasBottomLeft, canvasTopRight, canvasColor, -1);

		cout << "Canvas Bottom Left = " << canvasBottomLeft << ", Top Right = " << canvasTopRight;

		int lineThickness = 2;
		Point lineLeft(xcoordinate, ycoordinate);
		Point lineRight(xcoordinate + textWidth, ycoordinate);
		Scalar lineColor = Scalar(0, 255, 0);

		line(imageGetTextSize, lineLeft, lineRight, lineColor, lineThickness, LINE_AA);

		// Finally Draw the text
		putText(imageGetTextSize, text, Point(xcoordinate, ycoordinate), fontFace, fontScale,
			fontColor, fontThickness, LINE_AA);
		imshow("image with scaled text", imageGetTextSize);
	}

	catch (const std::exception & e)
	{
		cerr << "Error " << e.what() << endl;
	}
	
	


	const auto key = waitKey(0);
	cout << "Key pressed is : ascii value = " << key << ", printable: " << static_cast<char>(key) << endl;

	return 0;
}
