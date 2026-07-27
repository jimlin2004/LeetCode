#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
        題意: 找到子區間 i ~ j的sum >= k，求j - i最小

        因為陣列中有負數，所以不能用滑動窗戶

        解法是用單調隊列
        1. 
        當發現prefix[j] - prefix[front] >= k時
        front就不再需要了，這是因為題目要求j - i要最小
        由於現在front ~ j的區間已經 >= k，後續就算有front ~ j'的區間也符合 >= k
        j' - front > j - front，所以不需要紀錄front了
        2.
        j要放進去queue之前如果發現prefix[j] <= prefix[back]
        因為j > back且prefix[j] <= prefix[back]，
        所以j能夠比back更可能讓後續的j ~ j' >= k
        且j > back，區間長度會更短，所以back也不需要紀錄

        另外，一開始隊列中要多放個0

        這樣就可以O(N)了
    */
    int shortestSubarray(vector<int>& nums, int k)
    {
        int n = nums.size();

        vector<long long> prefix(n + 1, 0);
        for (int i = 1; i <= n; ++i)
        {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }

        deque<int> dq;

        int res = INT_MAX;

        // index 0，prefix[0] = 0
        dq.push_back(0);

        for (int i = 1; i <= n; ++i)
        {
            while (!dq.empty() && prefix[i] - prefix[dq.front()] >= k)
            {
                res = min(res, i - dq.front());
                dq.pop_front();
            }

            while (!dq.empty() && prefix[i] < prefix[dq.back()])
                dq.pop_back();
            
            dq.push_back(i);
        }

        return (res == INT_MAX) ? -1 : res ;
    }
};