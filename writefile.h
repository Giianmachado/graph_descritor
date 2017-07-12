#ifndef WRITEFILE_H
#define WRITEFILE_H
#include <string>

using namespace std;

class writeFile
{
    public:
        writeFile();
        void makeHeader(int r, int option, std::string filename);
        void writeClass(string filename, string class_of_image);
        void writeDouble(double value, string filename);
};

#endif // WRITEFILE_H
