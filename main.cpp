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
    int r = 50;
    int choice = 9;
    string  filename = "file.arff";
    string class_of_image = "Grass";

    //Declarations
    Mat img;
    vector<string> labels;
    vector<string> img_paths;

    //Get all labels in sequence of paths images
    labels = rf.readClasses("/home/gianluca/graph_descritor/labels");
    //Get all paths in file img_paths in sequence from folder
    img_paths = rf.readClasses("/home/gianluca/graph_descritor/paths");

    /**
     * First argument to makeHeader
     * 1 - average
     * 2 - standard deviation
     * 3 - 1 concat with 2
     *
     * 4 - Spanning tree average
     * 5 - Spanning tree standard deviation
     * 6 - 4 concat with 5
     *
     * 7 - 1 concat with 4
     * 8 - 2 concat with 5
     * 9 - 3 concat with 6
     */
    wf.makeHeader(r /*box size*/,choice /*type of descritor*/,filename /*filename*/);

    //Compute data
    for(int i = 0;i < labels.size()-1;i++){
        //Read the image
        img = imread(img_paths.at(i), CV_LOAD_IMAGE_GRAYSCALE);
        //Log
        cout << "Image " << i+1 << " processing" << endl;
        //Comput
        dac.compute(img /*image*/ ,r /*box size*/, choice /*type of descritor*/, filename /*filename*/, labels.at(i) /*class of image*/);
    }

    //return
    return 0;
}
