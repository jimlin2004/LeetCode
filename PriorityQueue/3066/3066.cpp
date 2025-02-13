#include <bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
        // 很單純的考min heap而已
        // 注意要用long long，被坑了
        int minOperations(vector<int>& nums, int k) 
        {
            priority_queue<long long , vector<long long>, greater<long long>> pq;
            for (int val: nums)
                pq.push(val);
            int res = 0;
            while (pq.size() > 1 && pq.top() < k)
            {
                ++res;

                long long a = pq.top();
                pq.pop();
                long long b = pq.top();
                pq.pop();

                pq.push(min(a, b) * 2 + max(a, b));
            }
            return res;
        }
};