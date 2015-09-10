#include "kdTree.hpp"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

  int main()
{
    ifstream datafile("../data/test.txt");
    vector<vector<double>> points;
    
    if (datafile) {
        string line;
        
        while (getline(datafile, line)) {
            points.push_back(vector<double>());
            stringstream split(line);
            double value;
            
            while (split >> value)
                points.back().push_back(value);
        }
    }
	
	// test tree construction
	shared_ptr<kdTree> k1 = shared_ptr<kdTree>(new kdTree(points));
	shared_ptr<kdTree> k2 = shared_ptr<kdTree>(new kdTree(points,"median"));
	shared_ptr<kdTree> k3 = shared_ptr<kdTree>(new kdTree(points,"mean"));
	shared_ptr<kdTree> k4 = shared_ptr<kdTree>(new kdTree(points,"median",1));
		
	// test insertion
	vector<double> v1 = {0.1,0.2,0.3};
	vector<double> v2 = {0,0,0};
	k1->insert(v1);
	k3->insert(v1);
	k3->insert(v2);
	
	// test save tree
	k1->saveTree("k1tree.txt");
	k2->saveTree("k2tree.txt");
	k3->saveTree("k3tree.txt");
	k4->saveTree("k4tree.txt");
	
	// test load tree
	string filename("k4tree.txt");
	shared_ptr<kdTree> k5 = shared_ptr<kdTree>(new kdTree(filename));
	k5->saveTree("k5tree.txt");
	//diff between k4tree and k5tree is empty hence validating the load from file
	
	// test nearest neighbor search
	int k = 2;
	vector<vector<double>> nPoints = k1->search(v2,k);
}
