
#include "Base.h"

void imageInfo(const Mat& image) {
    std::cout << "Image: size =" << image.size()
        << ", channels=" << image.channels()
        << ", type =" << typeToString(image.type())
        << ", depth =" << depthToString(image.type())
        << std::endl;
}
