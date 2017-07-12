#ifndef READFILE_H
#define READFILE_H
#include <string>
#include <vector>

using namespace  std;

class readfile
    {
    public:
        readfile();
        vector<string> readClasses(string path);
};

#endif // READFILE_H
