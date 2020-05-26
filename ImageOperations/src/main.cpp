#include "Base.h"
int main()
{
 /*
 1. Creating an image
  We use Mat(height, width, datatypeOfTheMatrix,
*/
    try
    {
    const auto height = 200; 
    const auto width = 400;
    Mat emptyMatrix = Mat(height, width,CV_8UC3, Scalar(0, 0, 0));

    // An 8 bit per color image, unsigned integers (0 - 255) with three channels
    // The pixels can take any value from 0 to 255. We set all the pixels to 0(black)
    //imshow("Empty Image before ",emptyMatrix);

    // Change the image pixels from black to white
    emptyMatrix.setTo(Scalar(255, 255, 255));

    //imshow("Empty Image after set to white ", emptyMatrix);


    // Create an empty matrix of the same size as the original image
    
    Mat emptyFromAnother = Mat(emptyMatrix.size(), emptyMatrix.type(), Scalar(100, 100, 100));

    //imshow("Copied from original", emptyFromAnother);


    //2. Cropping an image
    // We need to know where to crop i.e. the range of the rows and columns of interest
    
    const std::string path = "../../images/messi5.jpg";
   
        Mat original = imread(path, -1);
        cout << "Size of apple " << original.size() << endl; // [512 x 512]
        imshow("Original apple", original);

        // Crop using some random values
        // x coordinates = 170 to 320
        // y coordinates = 40 to 200
        Mat croppedApple = original(Range(40, 200), Range(170, 320));
        //imshow("Cropped Apple", croppedApple);

    // 3. Copying a region of an image to another 
    // Worth noting is the fact that the size of the rectangle that you cropped
    // is same as the area to paste it
    
        // Create a copy of the original image, hand
        Mat copiedImage = original.clone();
      //  imshow("Copied apple ", copiedImage);

    // Get roi
        Mat copyRoi = copiedImage(Range(40, 200), Range(180, 320));

        // Find height and width of the ROI
        int roiHeight = copyRoi.size().height;
        int roiWidth = copyRoi.size().width;

        // Copy to left of Face
        copyRoi.copyTo(copiedImage(Range(40, 40 + roiHeight), Range(10, 10 + roiWidth)));
        // Copy to right of Face
        copyRoi.copyTo(copiedImage(Range(40, 40 + roiHeight), Range(330, 330 + roiWidth)));

        imshow("Output image ", copiedImage);
    }
    catch (const std::exception&e)
    {
        cerr << "Error " << e.what() << endl;
    }
    catch (const cv::Exception & cve) {
        cerr << "Error " << cve.what() << endl;
    }
   


    const auto key = waitKey(0);
    cout << "Key pressed is : ascii value = " << key << ", printable: " << static_cast<char>(key) << endl;

    return 0;
}
