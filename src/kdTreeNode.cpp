#include "kdTreeNode.hpp"
#include <iostream>
kdTreeNode::kdTreeNode(vector<double> inValue, int axis, 
	shared_ptr<kdTreeNode> rightChild, shared_ptr<kdTreeNode> leftChild): 
	value(inValue),
	nodeaxis(axis),
	right(rightChild),
	left(leftChild)
{
	//Members initialized from the initialization list
	//do no additional work
}


void kdTreeNode::insert(const vector<double>& v)
{
	// Insert to the right tree if the value at the given dimension is greater
	if (v[nodeaxis] > value[nodeaxis]){
		if(right){	
			right->insert(v);
		}
		//If right is null create a new node for the tree
		else{
			right = shared_ptr<kdTreeNode>(new kdTreeNode(v,(nodeaxis+1)%v.size()));
		}
	}
	// Insert to the left tree if the value at the given dimension is lesser
	else{
		if(left){
			left ->insert(v);
		}
		//If left is null create a new node for the tree
		else{
			left = shared_ptr<kdTreeNode>(new kdTreeNode(v,(nodeaxis+1)%v.size()));
		}
	}
}

void kdTreeNode::writeTree(ofstream & out) 
{
  if (!this) 
  {
    out << "# "<< endl;
  } 
  else 
  {
    ostream_iterator<double> output_iterator(out, " ");
    copy(value.begin(), value.end(), output_iterator);
    out << endl;
    left->writeTree(out);
    right->writeTree(out);
  }
}

// Read tree: Constructor is overriden to create new kdTree from the file
kdTreeNode::kdTreeNode(string firstline, ifstream &fin, int axis) {

  nodeaxis = axis;
  string rightline,leftline;
  left = nullptr;
  right = nullptr;
        
  stringstream split(firstline);
  	double datapoint;
  	while (split >> datapoint){
  		value.push_back(datapoint);
  }
  	      
  getline(fin, leftline);
	
  if ((size_t)leftline.find("#") == string::npos){
  		left = shared_ptr<kdTreeNode> (new kdTreeNode(leftline,fin,axis+1)); 
  }
  
  getline(fin, rightline);
  if ((size_t)rightline.find("#") == string::npos){
  		right = shared_ptr<kdTreeNode> (new kdTreeNode(rightline,fin,axis+1)); 
  }
}

// Search for k nearest neighbors in the tree
void kdTreeNode::search(const vector<double>& v1,int& k, 
	priority_queue<vector<double>,vector<vector<double>>,distFinder>& p){
	p.push(value);
	if (p.size() > k){
		p.pop();
	}
	if (v1[nodeaxis] > value[nodeaxis]){
	  	if(right){
			right->search(v1,k,p);
		}
		else{
			if(p.size() < k){
				left->search(v1,k,p);
			}
		}
	}
	else{
		if(left){
			left->search(v1,k,p);
		}
		else{
			if(p.size() < k){
				right->search(v1,k,p);
			}
		}
	}
}

vector<double> kdTreeNode::getValue(){
	return value;
	}
kdTreeNode::~kdTreeNode(){
}
