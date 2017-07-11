#include <iostream>
#include <igraph/igraph.h>
#include <opencv2/opencv.hpp>
#include <divider_and_computer.h>
#include <utils.h>

using namespace std;
using namespace cv;

divider_and_computer dac;
utils u;

int main(int argc, char *argv[]){

    int r = 100;
    Mat img = imread("/home/gianluca/graph_descritor/textures/1.1.01.tiff", CV_LOAD_IMAGE_GRAYSCALE);
    //u.showImage(img);

    dac.compute(img,r);
    return 0;
}
