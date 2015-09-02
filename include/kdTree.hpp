#ifndef KDTREE_H
#define KDTREE_H

#include <string>
#include <memory>
#include <algorithm>
#include <vector>

using namespace std;
class kdTreeNode;

class kdTree {
private:
	string splitMethod;
	int dimension;
	unique_ptr<kdTreeNode> kdTreeRoot; 	
public:
	kdTree(vector<vector<double>> points, const string& split = "median",
		 int cutdimension=0, bool sortReq=False);
	~kdTree();
	
	size_t get_dimension() const;
	size_t size() const;
	bool empty() const;
	void insert(const kdTreeNode& node);
	bool search(const kdTreeNode& node) const;
 	//T& operator[] (const kdTreeNode<N>& node);
 	//T& at(const kdTreeNode<N>& node);
 	//const T& at(const kdTreeNode<N>& node) const;
};

#endif
