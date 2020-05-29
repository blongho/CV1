//Include file for standard system include files,
// or project specific include files.


#ifndef BASE_H
#define BASE_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <string>
#include <sstream>
using namespace cv;
using std::cout;
using std::endl;
using std::cerr; 

#define type2str(int) cv::typeToString(int)
void imageInfo(const Mat& image);

void imageInfo(const char* info, const Mat& image);
#endif
// TODO: Reference additional headers your program requires here.
