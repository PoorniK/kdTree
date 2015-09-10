#ifndef DISTFINDER_H
#define DISTFINDER_H

#include <stdexcept>
#include <functional>
#include <numeric>
#include <vector>

using namespace std;

double euclideanDist(const vector<double>& v1, const vector<double>& v2)
{
    if (v1.size() != v2.size())
        throw domain_error("Vectors must be of equal length");
    return inner_product(v1.begin(), v1.end(), v2.begin(), 0.0,
                   plus<double>(),[](double x,double y){return (y-x)*(y-x);});
}

class distFinder {
      vector<double> searchpoint;
public:
      distFinder(vector<double> inPoint) : searchpoint(inPoint) {}
      bool operator()(const std::vector<double>& point1, const std::vector<double>& point2) const {
            return euclideanDist(point1,searchpoint) > euclideanDist(point2,searchpoint);
      }      
};

#endif
