#ifndef KDTREE_H
#define KDTREE_H

#include <string>
#include <memory>
#include <algorithm>
#include <vector>
#include <stdexcept>

using namespace std;
class kdTreeNode;

class kdTree {
private:
	string splitMethod;
	int dimension;
	shared_ptr<kdTreeNode> kdTreeRoot; 	
public:
	kdTree(vector<vector<double>> points, const string& split = "median",
		 int cutdimension=0);
	~kdTree();
	kdTree(const string & filename);
	void insert(const vector<double>& point);
	vector<vector<double>> search(const vector<double>& point, int &k);
	void saveTree(const string & filename);

};

#endif
