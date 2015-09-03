#ifndef KDTREE_NODE_H
#define KDTREE_NODE_H

#include <memory>
#include <vector>

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
	
	void insert(const vector<double>& p);
	~kdTreeNode();
};

#endif
