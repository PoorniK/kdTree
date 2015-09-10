#include "kdTree.hpp"
#include "kdTreeNode.hpp"

template <typename T>
vector<T> slice(const vector<T>& v, int start=0, int end=-1) {
    int oldlen = v.size();
    int newlen;

    if (end == -1 or end >= oldlen){
        newlen = oldlen-start;
    } else {
        newlen = end-start;
    }

    vector<T> nv(newlen);

    for (int i=0; i<newlen; i++) {
        nv[i] = v[start+i];
    }
    return nv;
}

class sorter {
      int axis;
public:
      sorter(int inAxis) : axis(inAxis) {}
      bool operator()(const std::vector<double>& point1, const std::vector<double>& point2) const {
            return point1[axis] < point2[axis];
      }
};

//Construct the kdTree
kdTree::kdTree(vector<vector<double>> points, const string& method, 
			int cutdimension): 
		splitMethod(method){
	if (points.empty())
    {
    	kdTreeRoot = nullptr;
    	return;
    }
    // Select intial splitting axis
    int dimension = (int)(points[0].size());
    int axis = cutdimension % dimension;
    size_t lb1(0),lb2(0),ub1(0),ub2(0);
    size_t pivotLocation;
    size_t numpoints = points.size();
    if(numpoints == 1)
    {
    	kdTreeRoot = shared_ptr<kdTreeNode>(new kdTreeNode(points[0]));
    }
    else
    {
        sort(points.begin(), points.end(), sorter(axis));
        
    		if (method == "median")
    		{
    			pivotLocation = (size_t)(numpoints/2);
    			}
   			else if (method == "mean")
   			{
   				double mean(0.0);
   				for (size_t i=0;i<numpoints;i++)
   				{
   					mean = mean + points[i][axis];
   				}
   				mean =mean/(double)numpoints;
   				for (size_t i=0;i<numpoints;i++)
   				{
   					
   					if (points[i][axis]>= mean)
   					{
   						pivotLocation = i;
   						break;
   					}   						 
   				}

   			}
    
    /* lb1 = 0; */
    ub1 = pivotLocation;
    lb2 = pivotLocation +1;
    ub2 = (size_t)points.size();

	// Recursively create Left SubTree
 	unique_ptr<kdTree> left_child = move(unique_ptr<kdTree> (new kdTree(
 					slice<vector<double>>(points,lb1,ub1),
 										method,axis+1)));	

	// Recursively create Right SubTree
 	unique_ptr<kdTree> right_child = move(unique_ptr<kdTree> (new kdTree(
 					slice<vector<double>>(points,lb2,ub2),
 										method,axis+1)));
 	
 	kdTreeRoot = shared_ptr<kdTreeNode>(
    					new kdTreeNode(
    						points[pivotLocation],
    						axis,
    						right_child->kdTreeRoot,
    					 	left_child->kdTreeRoot));									
 	}										
}

//Insert element in a kdTree

void kdTree::insert(const vector<double>& v){
	if (!kdTreeRoot){
		kdTreeRoot = shared_ptr<kdTreeNode>(new kdTreeNode(v));
	}
	else {
		kdTreeRoot->insert(v);
	} 
}

//Search K-nearest neighbor of a give point

void kdTree::search(const vector<double>& v, int& k){
	priority_queue<vector<double>,vector<vector<double>>,distFinder> kNN(kdTreeRoot->getValue);
	
	if (!kdTreeRoot){
		return;
		}
	else{
		 kdTreeRoot->search(v,k,kNN);
	}
}

//Save KdTree to a file
void kdTree::saveTree(const string & filename)
{
	ofstream out(filename);
	kdTreeRoot->writeTree(out);
}

kdTree::~kdTree()
{
}
