#include "kdTreeNode.hpp"

kdTreeNode::kdTreeNode(vector<double> inValue, int axis, 
	shared_ptr<kdTreeNode> rightChild, shared_ptr<kdTreeNode> leftChild): 
	value(inValue),
	nodeaxis(axis),
	right(rightChild),
	left(leftChild)
{
	//do no work
}


void kdTreeNode::insert(const vector<double>& p)
{
	if (p[nodeaxis] > value[nodeaxis])
	{
		if(right)
		{	
			right->insert(p);
		}
		else
		{
			right = shared_ptr<kdTreeNode>(new kdTreeNode(p,(nodeaxis+1)%p.size()));
		}
	}
	else
	{
		if(left)
		{
			left ->insert(p);
		}
		else
		{
			left = shared_ptr<kdTreeNode>(new kdTreeNode(p,(nodeaxis+1)%p.size()));
		}
	}
}
