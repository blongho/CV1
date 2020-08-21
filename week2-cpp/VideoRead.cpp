//Include opencv header files
#include "opencv2/opencv.hpp"
#include <iostream>
#include "dataPath.hpp"

using namespace std;
using namespace cv;

int main() {
	VideoCapture cap(VIDEO_PATH + "chaplin.mp4");

	// Check if camera opened successfully and read a frame from the object cap
	if (!cap.isOpened()) {
		cout << "Error opening video stream or file" << endl;
		return -1;
	}


	int counter{};
	while (1) {

		Mat frame;
		// Capture frame-by-frame
		cap >> frame;

		// If the frame is empty, break immediately
		if (frame.empty())
			break;

		const double fps = cap.get(CAP_PROP_FPS);
		putText(frame, "fps=" + std::to_string(fps), Point(frame.rows / 2, frame.cols / 2), FONT_HERSHEY_DUPLEX, 1, Scalar(72, 72));
		// Display the resulting frame
		imshow("Frame", frame);


		// Press ESC on keyboard to exit
		char c = (char)waitKey(1);
		if (c == 27)
			break;
	}

	// When everything done, release the video capture object
	cap.release();

	// Closes all the frames
	destroyAllWindows();

	return 0;
}
