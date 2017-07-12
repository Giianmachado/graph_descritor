#ifndef DIVIDER_AND_COMPUTER_H
#define DIVIDER_AND_COMPUTER_H
#include <opencv2/opencv.hpp>
#include <string>

using namespace std;
using namespace cv;

class divider_and_computer
{
public:
    divider_and_computer();
    void compute(Mat img, int r, int choice, string filename, string class_of_image);
};

#endif // DIVIDER_AND_COMPUTER_H
