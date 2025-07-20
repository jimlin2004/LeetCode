#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    /*
        算簡單題

        因為要前n個 - 後n個最小
        所以greedy是前n個要最小 後n個要最大
        所以問題變成
        在[n, 2n]中我們要選一些數字
        使得前n個最小且後n個最大

        所以方法是用兩個heap
        前n個用maxHeap保持n個最小的數字
        後n個用minHeap保持n個最大的數字

        然後枚舉中間的[n, 2n]
        在這個區間中維護兩個heap表示par1的值與part2的值
        在[n, 2n]的每個位置i表示
        0 ~ i裡最小的前n個和在part1
        i ~ 3n裡最大的後n個和在part2
        一邊枚舉一邊維護最好的答案即可
    */
    long long minimumDifference(vector<int>& nums) 
    {
        int m = nums.size();
        int n = m / 3;

        long long p1 = 0;
        vector<long long> part1(n + 5, 0);

        priority_queue<int> maxHeap;
        for (int i = 0; i < n; ++i)
        {
            maxHeap.push(nums[i]);
            p1 += nums[i];
        }

        part1[0] = p1;
        for (int i = n; i < 2 * n; ++i)
        {
            maxHeap.push(nums[i]);
            p1 += nums[i];
            p1 -= maxHeap.top();
            maxHeap.pop();

            part1[i - n + 1] = p1;
        }

        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long part2 = 0;
        for (int i = m - 1; i >= m - n; --i)
        {
            minHeap.push(nums[i]);
            part2 += nums[i];
        }
        
        // 枚舉答案
        long long res = part1[n] - part2;

        for (int i = 2 * n - 1; i >= n; --i)
        {
            minHeap.push(nums[i]);
            part2 += nums[i];
            part2 -= minHeap.top();
            minHeap.pop();

            res = min(res, part1[i - n] - part2);
        }

        return res;
    }
};


int main()
{
    Solution S;
    vector<int> nums = {3, 1, 2};
    S.minimumDifference(nums);

    return 0;
}