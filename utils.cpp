#include "utils.h"
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

utils::utils(){}

//Function to show image
void utils::showImage(Mat img){
    namedWindow("image", 2);
    imshow("image", img);
    waitKey(0);
}
