#include <bits/stdc++.h>
using namespace  std;

class Solution 
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        vector<int> ans;   
        priority_queue<pair<int,int>> pq;
        int i = 0, j = 0;
        while (j < nums.size())
        {
            pq.push({nums[j], j});
            if (j - i + 1 < k)
                j++;
            else
            {
                ans.push_back(pq.top().first);
                i++;
                j++;
                while(!pq.empty() && pq.top().second < i)
                    pq.pop();
            }
        }
        return ans;
    }
};