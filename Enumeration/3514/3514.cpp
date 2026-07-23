#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    /*
        這是題目的第二題，第一題是3513
        但這題更簡單，不用思考數學
        因為nums.size()最大只有1500
        所以直接枚舉就行了
        (其實下方解法應該可能達到O(N ^ 3))
    */
    unordered_set<int> allTwoXOR;
    unordered_set<int> allThreeXOR;
    int uniqueXorTriplets(vector<int>& nums) 
    {
        int n = nums.size();

        // 先將nums[i] ^ nums[j]的紀錄下來
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                allTwoXOR.insert(nums[i] ^ nums[j]);
            }
        }

        // 然後再讓每個數字與之前twoXOR的所有數字再做一次即可
        // 因為i <= j <= k，所以順序根本不重要
        for (int val: nums)
        {
            for (int twoXOR: allTwoXOR)
            {
                allThreeXOR.insert(val ^ twoXOR);
            }
        }

        return allThreeXOR.size();
    }
};