#pragma once

#include <fstream>
#include <string>
using namespace std;

class SaveFile{
private:
   streampos fileSize;//streampos data type holds current position of the buffer pointer or file pointer
   char* memBlock;
   string fileName;
public:
   SaveFile();
   ~SaveFile();

   streampos getSize();
   char* getMemBlock();

};
