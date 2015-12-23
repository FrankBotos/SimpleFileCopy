# SimpleFileCopy
A simple C++ program that converts a file to binary, then makes an exact duplicate on the hard drive. It is a very simple program and it should be relatively easy to compile this as it stands without any dependencies whatsoever. Although it is a simple program I do believe that it can have some interesting applications where the transferring and copying of files is concerned.

#Latest Version
With the latest version, I have condensed the classes into a single class called "FileCopier." The intial program worked perfectly up to a certain file size, dependant on the hardware running the code, however I quickly noticed that if one wanted to copy very large files, it was impossible to do by copying the entire file into RAM. And so, with this latest update, the program implements a buffer that saves only chunks of the file into the RAM, writes that chunk, and then moves onto the next chunk. This makes the copying of very large files possible.
