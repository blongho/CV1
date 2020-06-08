#include "ContrastAndBrightness.h"
using std::cout;
using std::endl;
using std::cin;

void transform(Mat &image) {
    Mat new_image = Mat::zeros(image.size(), image.type());
    double alpha = 1.0; /*< Simple contrast control */
    int beta = 0;       /*< Simple brightness control */
    cout << " Basic Linear Transforms " << endl;
    cout << "-------------------------" << endl;
    cout << "* Enter the alpha value [1.0-3.0]: "; cin >> alpha;
    cout << "* Enter the beta value [0-100]: ";    cin >> beta;
    for (int y = 0; y < image.rows; y++) {
        for (int x = 0; x < image.cols; x++) {
            for (int c = 0; c < image.channels(); c++) {
                new_image.at<Vec3b>(y, x)[c] = // Get individual pixel values and assign new values
                    saturate_cast<uchar>(alpha * image.at<Vec3b>(y, x)[c] + beta); // staturate_cast<uchar> corrects for overflow
            }
        }
    }
    // Notice that the above for loop can be replaced by 
   // image.convertTo(new_image, -1, alpha, beta); // <-- Is more optimzed and works faster. Prefer it. 

    imshow("Original Image", image);
    imshow("New Image", new_image);
    waitKey();
}
void gammaCorrection(Mat& image, const float gamma) {
    imshow("Original image before transform", image);

    Mat lookUpTable(1, 256, CV_8U);
    uchar* p = lookUpTable.ptr();
    for (int i = 0; i < 256; ++i)
        p[i] = saturate_cast<uchar>(pow(i / 255.0, gamma) * 255.0);
    Mat res = image.clone();
    LUT(image, lookUpTable, res);
    const std::string info = "Transformed with gamm " + std::to_string(gamma);
    imshow(info, res);
}
