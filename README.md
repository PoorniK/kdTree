# kdTree
This repository contains a simple implementation of kdTree with the following constrains:
* Construction/destruction (RAII style)
* Create a tree from a set of points in an N-dimensional space 
* Create a tree on the fly from points as they come in 
* Support efficient exact query for k-nearest points 
* Support I/O to save/load the tree from disk
* The splitting method takes in either mean or median (median being the default)

#Build instructions

Use g++ to build a shared static library from the src repository
The Makefile is included in the src folder

$ cd <root>/src
$ make

Make also builds an executable from the test file located in the test folder. The executable and the library and generated in the bin and the lib folders respectively. The test file contains unit tests. To run the test:

$ cd <root>/bin
$ ./testkdTree
