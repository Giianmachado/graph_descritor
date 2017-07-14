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
    void abort_programa();
    bool verify_r(int r);
    void print_divider();
    void print_information_author();
    void print_error_r();
    void print_error_choice();
};

#endif // UTILS_H
