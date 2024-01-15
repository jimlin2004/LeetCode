#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int> pq;
        for (int n: nums)
            pq.push(n);
        k--;
        while (k--)
            pq.pop();
        return pq.top();
    }
};