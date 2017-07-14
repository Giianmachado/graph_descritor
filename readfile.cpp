#include "readfile.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace  std;

readfile::readfile(){}

/**
 * @brief readfile::readClasses
 * @param path
 * @return
 */
vector<string> readfile::readClasses(string path){
    //Get line
    string line;
    //vector of results
    vector<string> list;
    //object
    fstream fs;
    //file rules
    fs.open(path.c_str(), std::fstream::in | std::fstream::out | std::fstream::app);

    while(!fs.eof()){
        getline(fs,line);
        list.push_back(line);
    }

    //Close file
    fs.close();
    return list;
}
