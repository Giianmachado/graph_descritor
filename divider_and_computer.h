#ifndef DIVIDER_AND_COMPUTER_H
#define DIVIDER_AND_COMPUTER_H
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

class divider_and_computer
{
public:
    divider_and_computer();
    void compute(Mat img, int r);
};

#endif // DIVIDER_AND_COMPUTER_H
