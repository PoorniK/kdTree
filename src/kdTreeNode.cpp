#include "kdTreeNode.hpp"

kdTreeNode::kdTreeNode(vector<double> inValue,unique_ptr<kdTreeNode> left, unique_ptr<kdTreeNode> right) : value(inValue)
{
	this->left = left;
	this->right = right;
}
