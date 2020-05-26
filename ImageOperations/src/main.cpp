#include "Base.h"
int main()
{
 /*
 1. Creating an image
  We use Mat(height, width, datatypeOfTheMatrix,
*/
    const auto height = 200; 
    const auto width = 400;
    Mat emptyMatrix = Mat(height, width,CV_8UC3, Scalar(0, 0, 0));

    // An 8 bit per color image, unsigned integers (0 - 255) with three channels
    // The pixels can take any value from 0 to 255. We set all the pixels to 0(black)
    imshow("Empty Image before ",emptyMatrix);

    // Change the image pixels from black to white
    emptyMatrix.setTo(Scalar(255, 255, 255));

    imshow("Empty Image after set to white ", emptyMatrix);


    // Create an empty matrix of the same size as the original image
    
    Mat emptyFromAnother = Mat(emptyMatrix.size(), emptyMatrix.type(), Scalar(100, 100, 100));

    imshow("Copied from original", emptyFromAnother);
    const auto key = waitKey(0);
    cout << "Key pressed is : ascii value = " << key << ", printable: "  << static_cast<char>(key) << endl;
    return 0;
}
