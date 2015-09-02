#ifndef KDTREE_NODE_H
#define KDTREE_NODE_H

#include <memory>
#include <vector>

using namespace std;

class kdTreeNode
{
private:
	vector<double> value;
	unique_ptr<kdTreeNode> left;
	unique_ptr<kdTreeNode> right;

public:
	kdTreeNode(vector<double> value,unique_ptr<kdTreeNode> left = NULL , unique_ptr<kdTreeNode> right = NULL);
	~kdTreeNode();
};

#endif
