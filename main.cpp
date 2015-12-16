#include <iostream>
#include "SaveFile.h"
#include "WriteFile.h"

int main(){
   SaveFile f1;
   WriteFile f2(f1);
   return 0;
}
