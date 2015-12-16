#include <iostream>
#include "WriteFile.h"

WriteFile::WriteFile(SaveFile sf){
   cout << "Please enter new file name: ";
   cin >> fileName;
   ofstream file(fileName, ios::out|ios::binary);
   file.write(sf.getMemBlock(), sf.getSize());
   file.close();
}

WriteFile::~WriteFile(){}
