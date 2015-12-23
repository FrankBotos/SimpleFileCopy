#include "FileCopier.h"
#include <iostream>
using namespace std;

FileCopier::FileCopier(){
   //initialize chunk size
   chunkSize = CHUNK_BYTES;
   oneChunk = true;

   /*
   ALGORITHM:
   1.get fileNames
   2.define chunk size
   3.find file size
   4.find # of chunks needed
   5.save a chunk, write that chunk, repeat until all data is written
   */
   setFileNames();
   findFileSize();
   findNumChunks();
   doWork();

}
FileCopier::~FileCopier(){}

void FileCopier::setFileNames(){
   //get input file name
   cout << "File name: ";
   cin >> iFileName;

   //set output file name
   cout << "New file name: ";
   cin >> oFileName;
}

void FileCopier::findFileSize(){
   iFile = ifstream(iFileName, ios::in | ios::binary | ios::ate);//ios ate sets position get pointer to end of file
   if (iFile.is_open()){
      fileSize = iFile.tellg();//because get pointer is at end of file, this will reveal file size in bytes
      iFile.seekg(0, ios::beg);//resets file pointer to beginning
   }
}

void FileCopier::findNumChunks(){
   if (fileSize > chunkSize){
      oneChunk = false;
      numChunks = fileSize / chunkSize;
   }
   else {
      numChunks = 1;
   }
}

void FileCopier::doWork(){//once all data is avaialble, actually copy file
   oFile = ofstream(oFileName, ios::out | ios::binary);

   if (oneChunk){//if entire file fits into single chunk, this block executes
      char* currentChunk = new char[fileSize];
      iFile.read(currentChunk, fileSize);
      oFile.write(currentChunk, fileSize);
      delete[] currentChunk;
   }
   else {//if more than one chunks needed, this block executes + makes sure last chunk is correct size
      uint32_t chunksWritten = 0;
      while (chunksWritten <= numChunks){

         if (chunksWritten != numChunks){
            currentChunk = new char[chunkSize];
            iFile.read(currentChunk, chunkSize);
            oFile.write(currentChunk, chunkSize);
            delete[] currentChunk;
         }
         else {//this block will execute on final chunk!
            uint32_t lastChunkSize = fileSize - (chunkSize * numChunks);
            currentChunk = new char[lastChunkSize];
            iFile.read(currentChunk, lastChunkSize);
            oFile.write(currentChunk, lastChunkSize);
            delete[] currentChunk;
         }
         cout << "chunks: " << chunksWritten << "/" << numChunks << "\n";
         chunksWritten++;
      }
   }
}