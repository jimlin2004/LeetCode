#include <bits/stdc++.h>
using namespace std;

class MedianFinder 
{
public:
    MedianFinder() 
    {
        
    }
    
    void addNum(int num) 
    {
        if (!vec.size())
            vec.push_back(num);
    }
    
    double findMedian() 
    {
        
    }
private:
    vector<double> vec;
};