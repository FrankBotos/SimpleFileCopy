#pragma once
#include <string>
#include <fstream>
#include <stdint.h>

#define CHUNK_BYTES 64000000 //64mb chunk

class FileCopier{
private:

   std::string iFileName;//input file name
   std::string oFileName;//output file name
   std::ifstream iFile;//input file
   std::ofstream oFile;//output file
   uint32_t chunkSize;//size of chunks to use for copying (size in bytes)
   uint32_t fileSize;//size of file in bytes
   uint32_t numChunks;//total number of chunks
   bool oneChunk;//true if only need 1 chunk
   char* currentChunk;//will hold the bytes of the current chunk
public:
   FileCopier();
   ~FileCopier();

   void setFileNames();
   void findFileSize();
   void findNumChunks();
   void doWork();

};