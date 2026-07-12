#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 好像極限就是O(N log N)
    vector<int> arrayRankTransform(vector<int>& arr) 
    {
        vector<int> sortedArr(arr);
        sort(sortedArr.begin(), sortedArr.end());
        int m = unique(sortedArr.begin(), sortedArr.end()) - sortedArr.begin();

        unordered_map<int, int> numToRank;
        for (int i = 0; i < m; ++i)
        {
            numToRank[sortedArr[i]] = i + 1;
        }

        vector<int> res(arr);
        for (int& val: res)
        {
            val = numToRank[val];
        }

        return res;
    }
};