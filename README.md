# kdTree
This repository contains a simple implementation of kdTree with the following constrains:
* Construction/destruction (RAII style)
* Create a tree from a set of points in an N-dimensional space 
* Create a tree on the fly from points as they come in 
* Support efficient exact query for k-nearest points 
* Support Best Bin First query for k-nearest points limited to exploring M nodes 
* Support I/O to save/load the tree from disk

#Build instructions

Use g++ to build a shared static library from this repository

$ cd <root>/src
$ make
