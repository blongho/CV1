
#include "Base.h"

void imageInfo(const char * info, const Mat& image) {
    std::cout << info;
    std::cout << " size =" << image.size()
        << ", channels=" << image.channels()
        << ", type =" << typeToString(image.type())
        << ", depth =" << depthToString(image.type()) << " -> " <<(int)image.at<uchar>(0)

        << std::endl;
}
void imageInfo(const Mat& image) {
    std::cout << "Image: size =" << image.size()
        << ", channels=" << image.channels()
        << ", type =" << typeToString(image.type())
        << ", depth =" << depthToString(image.type())
        << std::endl;
}
