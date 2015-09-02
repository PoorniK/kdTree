#include "kdTree.hpp"
#include "kdTreeNode.hpp"

//Construct the kdTree
kdTree::kdTree(vector<vector<double>> points, const string& method, 
			int cutdimension, bool sortReq): 
		splitMethod(method), 
		dimension((int)points[0].size())

{
		
   // Select intial splitting axis
   int axis = cutdimension % this->dimension;
   
   if (sortReq){     
   		points = kdtree::sort(points,cut_dimension);
   	}
   	
 	this->kdTreeRoot = new kdTreeNode(points[(int)(points.size()/2)])

 	unique_ptr<kdtree> left_child = new kdtree(slice(points,0,points.size()/2),
 										"median",cutdimension+1);	
    this->kdTreeRoot->left = left_child->kdTreeRoot;

 	unique_ptr<kdtree> right_child = new kdtree(slice(points,0,points.size()/2),
 										"median",cutdimension+1);	
    this->kdTreeRoot->right = right_child->kdTreeRoot;
}

kdTree::sort(vector<vector<double>> points)
{
	
}

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
