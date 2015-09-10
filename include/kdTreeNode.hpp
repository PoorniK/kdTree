#ifndef KDTREE_NODE_H
#define KDTREE_NODE_H

#include <memory>
#include <vector>
#include <fstream>
#include <queue>
#include <iterator>
#include <sstream>
#include "distFinder.hpp"

using namespace std;
class kdTree;

class kdTreeNode
{
friend class kdTree;
private:
	vector<double> value;
	int nodeaxis;
	shared_ptr<kdTreeNode> left;
	shared_ptr<kdTreeNode> right;

public:
	kdTreeNode(vector<double> value, int nodeaxis = 0, 
		shared_ptr<kdTreeNode> = nullptr, shared_ptr<kdTreeNode> = nullptr);
	
	void insert(const vector<double>& v);
	void search(const vector<double>& v, int & k, priority_queue<vector<double>,vector<vector<double>>,distFinder>& p);
	void writeTree(ofstream & out);
	vector<double> getValue();
	kdTreeNode(string firstline, ifstream & in,int axis);
	~kdTreeNode();
};


#endif
