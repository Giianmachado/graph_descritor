#include <iostream>
#include <igraph/igraph.h>
#include <opencv2/opencv.hpp>
#include <divider_and_computer.h>
#include <utils.h>
#include <writefile.h>
#include <string>
#include <readfile.h>
#include <vector>
#include <unistd.h>

using namespace std;
using namespace cv;

divider_and_computer dac;
utils u;
writeFile wf;
readfile rf;

int main(int argc, char *argv[]){

    // Gets r value -r
    int r = atoi(argv[2]);

    //Verify r value
    if(!u.verify_r(r)) u.print_error_r();

    //Get choice value
    int choice = atoi(argv[4]);

    //Verify choice value
    if(choice < 1 || choice > 9) u.print_error_choice();

    //string  filename = "file.arff"; -f
    string  filename = argv[6];

    //Declarations
    Mat img;
    vector<string> labels;
    vector<string> img_paths;
    vector<string> classes;

    //Get all labels in sequence of paths images
    labels = rf.readClasses("/home/gianluca/graph_descritor/labels");
    //Get all paths in file img_paths in sequence from folder
    img_paths = rf.readClasses("/home/gianluca/graph_descritor/paths");
    //Get all the classes of file .arff
    classes = rf.readClasses("/home/gianluca/graph_descritor/paths");

    //Print author information and sleep 10 sec
    u.print_information_author();

    //Build header file
    wf.makeHeader(r /*box size*/,choice /*type of descritor*/,filename /*filename*/);

    //Compute data
    for(int i = 0;i < labels.size()-1;i++){
        //Read the image
        img = imread(img_paths.at(i), CV_LOAD_IMAGE_GRAYSCALE); //Verificar se existe a imagem
        //Log
        cout << "Image " << i+1 << " processing" << endl;
        //Comput
        dac.compute(img /*image*/ ,r /*box size*/, choice /*type of descritor*/, filename /*filename*/, labels.at(i) /*class of image*/);
    }

    //return
    return 0;
}
