#ifndef UTILS_H
#define UTILS_H
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class utils
{
public:
    utils();
    void showImage(Mat img);
    int maxDivisor(Mat img, int r);
};

#endif // UTILS_H
