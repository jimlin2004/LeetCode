#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    //要思考的題目
    //利用雙指標l, r
    //l代表現在的位置
    //r是目前最遠能到的位置
    //其意義是l ~ r是當前知道能夠1步之內到達的範圍
    //因此當r還不是終點時代表需要多一次跳躍
    //所以可以一邊維護一邊紀錄需要最少幾次跳躍
    //雙指標+greedy
    int jump(vector<int>& nums)
    {
        int l = 0;
        int r = nums[0];
        int target = nums.size() - 1;
        if (target == 0)
            return 0;
        int res = 1;
        while (r < target)
        {
            ++res;
            int far = r;
            for (int i = l; i <= r; ++i)
                far = max(far, i + nums[i]);
            l = r + 1;
            r = far;
        }
        return res;
    }
};