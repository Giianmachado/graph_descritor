#include "writefile.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>

using namespace std;

writeFile::writeFile(){}

/**
 * @brief writeFile::makeHeader
 * @param r
 * @param option
 * @param filename
 * Makes the header of arff file
 */
void writeFile::makeHeader(int r,int option, string filename){

    //number of attributtes to print on arff
    int num_of_attributes;
    //Writer
    fstream fs;
    //file rules
    fs.open(filename, std::fstream::in | std::fstream::out | std::fstream::app);
    //conter to attributtes
    int cont = 1;

    //Decides operations from number of attributes
    if(option == 1 || option == 2)
        num_of_attributes = r*r*4;
    else if(option == 4 || option == 5)
        num_of_attributes = r*r;
    else if(option == 3)
        num_of_attributes = r*r*8;
    else if(option == 6)
        num_of_attributes = r*r*2;
    else if(option == 7 || option == 8)
        num_of_attributes = r*r*5;
    else if(option == 9)
        num_of_attributes = r*r*10;

    //Title o work
    fs << "@RELATION IC" << endl << endl;
    for(int i = 0; i < num_of_attributes; i++)
        fs << "@attribute Media" << cont++ << " numeric" << endl;

    fs << "@attribute class {";
    fs << "Grass,";
    fs << "Bark,";
    fs << "Straw,";
    fs << "HerringboneWeave,";
    fs << "WoolenCloth,";
    fs << "PressedCalfLeather,";
    fs << "BeachSand,";
    fs << "Water,";
    fs << "WoodGrain,";
    fs << "Raffia,";
    fs << "Pigskin,";
    fs << "BrickWall,";
    fs << "PlasticBubbles,";
    fs << "WoodShingleRoof,";
    fs << "TileRoof,";
    fs << "WoodFence,";
    fs << "MetalGrates,";
    fs << "Sand,";
    fs << "HexagonalHoleArray,";
    fs << "RoughWall,Gravel";
    fs << "}" << endl << endl << "@data" << endl;

    //Close the file
    fs.close();
}

/**
 * @brief writeFile::writeClass
 * @param filename
 * @param class_of_image
 */
void writeFile::writeClass(string filename, string class_of_image){
    //Writer
    fstream fs;
    //file rules
    fs.open(filename, std::fstream::in | std::fstream::out | std::fstream::ate);
    //Write class
    fs << class_of_image << endl;
    //close file
    fs.close();
}

/**
 * @brief writeFile::writeDouble
 * @param aux
 * @param filename
 */
void writeFile::writeDouble(double value, string filename){
    //Writer
    fstream fs;
    //file rules
    fs.open(filename, std::fstream::in | std::fstream::out | std::fstream::ate);
    //Write class
    fs << value << ",";
    //close file
    fs.close();
}
