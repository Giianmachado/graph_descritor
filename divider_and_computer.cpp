#include "divider_and_computer.h"
#include <opencv2/opencv.hpp>
#include <utils.h>
#include <graph.h>

using namespace std;
using namespace cv;

divider_and_computer::divider_and_computer(){}

void divider_and_computer::compute(Mat img, int r){

    //Util function as showImage
    utils u;
    //Class to build a graph and calculate the values
    graph g;
    //Define the number of pixel will be cutted
    int max = floor(img.cols/r);
    //Aux img to img cutted
    Mat img_rect;
    //Variable to define region of interest
    Rect region_of_interest;

    //Loop to divide rxr boxes from image
    for(int i = 0;i < r*max;i+=max){
        for(int j = 0;j < r*max;j+=max){
            //Region of interest
            region_of_interest = Rect(i,j,max,max);
            //Cut image
            img_rect = img(region_of_interest);
            //Call the function to build a graph and calculate the values
            g.build_graph(img_rect);
        }
    }
}
