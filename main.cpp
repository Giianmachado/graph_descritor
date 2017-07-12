#include <iostream>
#include <igraph/igraph.h>
#include <opencv2/opencv.hpp>
#include <divider_and_computer.h>
#include <utils.h>
#include <writefile.h>
#include <string>
#include <readfile.h>
#include <vector>

using namespace std;
using namespace cv;

divider_and_computer dac;
utils u;
writeFile wf;
readfile rf;

int main(/*int argc, char *argv[]*/){

    /**
     * Can be: 100 50 40 25 20 10 8 5 4
     */
    int r = 4;
    int choice = 1;
    string  filename = "file.arff";
    string class_of_image = "Grass";

    //Declarations
    Mat img;
    vector<string> labels;
    vector<string> img_paths;

    //Get all labels in sequence of paths images
    labels = rf.readClasses("/home/gianluca/graph_descritor/labels");
    //Get all paths in file img_paths in sequence from folder
    img_paths = rf.readClasses("/home/gianluca/graph_descritor/labels");

    /**
     * First argument to makeHeader
     * 1 - average
     * 2 - standard deviation
     * 3 - average concat standard deviation
     *
     * 4 - average + shortest spanning tree average
     * 5 - standard deviation + shortest spanning tree standard deviation
     * 6 - average + shortest spanning tree average + standard deviation + shortest spanning tree standard deviation
     */
    //wf.makeHeader(r /*box size*/,choice /*type of descritor*/,filename /*filename*/);

    //Read the image
    img = imread("/home/gianluca/graph_descritor/textures/1.1.01.tiff", CV_LOAD_IMAGE_GRAYSCALE);

    //Compute data
    for(int i = 0;i < labels.size();i++){
        //dac.compute(img /*image*/ ,r /*box size*/, choice /*type of descritor*/, filename /*filename*/, class_of_image /*class of image*/);
        cout << labels.at(i) << endl;
        cout << img_paths.at(i) << endl;
    }

    //return
    return 0;
}
