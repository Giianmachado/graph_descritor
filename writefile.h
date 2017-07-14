#ifndef WRITEFILE_H
#define WRITEFILE_H
#include <string>
#include <vector>

using namespace std;

class writeFile
{
    public:
        writeFile();
        void makeHeader(int r, int option, std::string filename, vector<string> classes);
        void writeClass(string filename, string class_of_image);
        void writeDouble(double value, string filename);
};

#endif // WRITEFILE_H
