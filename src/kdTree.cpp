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

//Construct the kdTree
kdTree::kdTree(vector<vector<double>> points, const string& method, 
			int cutdimension): 
		splitMethod(method), 
		dimension((int)points[0].size()){
		
    // Select intial splitting axis
    axis = cutdimension % dimension;
    
    int lb1(0),lb2(0),ub1(0),ub2(0);
    int pivotLocation;
    if(points.size() == 1)
    {
    	kdTreeRoot = shared_ptr<kdTreeNode>(new kdTreeNode(points[0]));
    }
    else if (points.empty())
    {
    	kdTreeRoot = nullptr;
    }
    else
    {
        sort(points.begin(), points.end(),
       [](const std::vector<double>& point1, const std::vector<double>& point2) {
          return point1[axis] < point2[axis];
          });
        
        int intMethod(0);
        if (method == "median"){ intMethod = 1;}
        if (method == "mean"){intMethod = 2;}  
    	switch(intMethod)
    	{
    		case 1:
    			pivotLocation = (int)(points.size()/2);
    			break;
   			case 2:
   			    {
   				double mean(0);
   				for (int i=0;i++;i<(int)points.size())
   				{
   					mean = mean + points[i][axis];
   				}
   				mean /=2;
   				for (int i=0;i++;i<(int)points.size())
   				{
   					
   					if (points[i][axis]> mean)
   					{
   						pivotLocation = i;
   						break;
   					}   						 
   				}
   				break;
   				}
   			default:
   				break;
   		}
    
    /* lb1 = 0; */
    ub1 = pivotLocation -1;
    lb2 = pivotLocation +1;
    ub2 = (int)points.size();
	
	// Create Left SubTree
 	unique_ptr<kdTree> left_child = move(unique_ptr<kdTree> (new kdTree(
 					slice<vector<double>>(points,lb1,ub1),
 										method,axis+1)));	

	// Create Right SubTree
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

void kdTree::insert(const vector<double>& p)
{
	if (!kdTreeRoot)
	{
		kdTreeRoot = shared_ptr<kdTreeNode>(new kdTreeNode(p));
	}
	else 
	{
		kdTreeRoot->insert(p);
	} 
}
