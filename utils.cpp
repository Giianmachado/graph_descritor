#include "utils.h"
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

utils::utils(){}

/**
 * @brief utils::showImage
 * @param img
 * Show image
 */
void utils::showImage(Mat img){
    namedWindow("image", 2);
    imshow("image", img);
    waitKey(0);
}

/**
 * @brief utils::maxDivisor
 * @param r
 * return max divisor to the r boxes
 */
int utils::maxDivisor(Mat img, int r){
    return floor(img.cols/r);
}
