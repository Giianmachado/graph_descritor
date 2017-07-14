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

    //Verify how many arguments
    if(argc != 13)
        u.print_error_r("Few arguments to execute.");

    // Gets r value -r
    string comp = argv[1];
    if(comp != "-r") u.print_error_r("The argument -r is invalid or in wrong position.");
    int r = atoi(argv[2]);

    //Verify r value
    if(!u.verify_r(r)) u.print_error_r("The argument r is invalid");

    //Get choice value -c
    comp = argv[3];
    if(comp != "-c") u.print_error_r("The argument -c is invalid or in wrong position.");
    int choice = atoi(argv[4]);

    //Verify choice value
    if(choice < 1 || choice > 9) u.print_error_choice();

    //string  filename = "file.arff"; -f
    comp = argv[5];
    if(comp != "-f") u.print_error_r("The argument -f is invalid or in wrong position.");
    string  filename = argv[6];

    //Declarations
    Mat img;
    vector<string> labels;
    vector<string> img_paths;
    vector<string> classes;

    //Get all labels in sequence of paths images -l
    comp = argv[7];
    if(comp != "-l") u.print_error_r("The argument -l is invalid or in wrong position.");
    labels = rf.readClasses(argv[8]);
    //Get all paths in file img_paths in sequence from folder -p
    comp = argv[9];
    if(comp != "-p") u.print_error_r("The argument -p is invalid or in wrong position.");
    img_paths = rf.readClasses(argv[10]);
    //Get all the classes of file .arff -cl
    comp = argv[11];
    if(comp != "-cl") u.print_error_r("The argument -cl is invalid or in wrong position.");
    classes = rf.readClasses(argv[12]);

    if(labels.size() != img_paths.size())
        u.print_error_r("Diferents sizes to labels file and images path file.");

    //Print author information and sleep 10 sec
    u.print_information_author();

    //Print file options
    u.print_file_options(r,choice,filename,argv[8],argv[10],argv[12]);

    //Build header file
    wf.makeHeader(r /*box size*/,choice /*type of descritor*/,filename /*filename*/, classes /*Classes*/);

    //Compute data
    int len = labels.size();
    for(int i = 0;i < len;i++){
        //Read the image
        img = imread(img_paths.at(i), CV_LOAD_IMAGE_GRAYSCALE); //Verificar se existe a imagem
        if (img.data == 0) {
            cerr << "Image " << img_paths.at(i) <<" not found!" << endl;
            u.abort_programa();
        }else{
            //Log
            cout << "Image " << i+1 << " processing..." << endl;
            //Comput
            dac.compute(img /*image*/ ,r /*box size*/, choice /*type of descritor*/, filename /*filename*/, labels.at(i) /*class of image*/);
        }
    }

    u.print_error_r("Program execute succefully. The file is " + filename);
    //return
    return 0;
}
