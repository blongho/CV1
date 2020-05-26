#include "Base.h"
int main()
{
    const std::string path = "D:\\images\\Grab\\image (37).png";
    Mat mat = imread(path);
    imshow("Image", mat);
    waitKey(0);
    return 0;
}
