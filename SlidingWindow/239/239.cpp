#include <bits/stdc++.h>
using namespace  std;

class Solution 
{
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        vector<int> res;
        vector<int>::iterator slow = nums.begin();
        vector<int>::iterator fast = slow + (k - 1);
        priority_queue<pair<int, vector<int>::iterator>> pq;
        while (fast != nums.end())
        {
            for (vector<int>::iterator it = slow; it != (fast + 1); it++)
                pq.push({*it, it});
            res.push_back(pq.top().first);
            slow++;
            fast++;
            while (!pq.empty() && pq.top().second < slow)
                pq.pop();
        }
        return res;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    obj.maxSlidingWindow(nums, 3);
    return 0;
}