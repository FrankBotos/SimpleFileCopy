#pragma once

#include <fstream>
#include <string>
#include "SaveFile.h"
using namespace std;

class WriteFile{
private:
   string fileName;
   streampos fileSize;
   char* memBlock;
public:
   WriteFile(SaveFile sf);
   ~WriteFile();
};
