#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 算有難度的題
    // 可以發現可以交換是有transtive的，如{1, 3, 5}在limit = 2情況下
    // 所有的排列都是可以交換出來的，而我們希望數字越小的在越前面
    // 以下有參考題解
    // 利用排序過的nums
    // 只要檢查sortedNums[i] - sortedNums[i - 1] <= limit
    // 代表它們可以互相交換
    // 我們將所有可以交換的分成一個個group
    // 由於sort過，所以此時記在group是由小到大的
    // 只要迭代nums看每個nums[i]屬於哪個group，只要將改group目前最前面
    // 的元素拿來輸出即可，group記得要標記用到哪些元素
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) 
    {
        int n = nums.size();
        // 將nums排序
        vector<int> sortedNums(nums);
        sort(sortedNums.begin(), sortedNums.end());
        // 數字對應到第幾個group(需要用map離散化，不用怕覆蓋問題，數字一樣一定在同個group)
        unordered_map<int, int> posToGroup;
        vector<vector<int>> groups;
        // groupsPtr[i] = p -> 第i個group現在指到第p個位置
        vector<int> groupsPtr;
        
        //分group
        groups.emplace_back(vector<int>({sortedNums[0]}));
        groupsPtr.emplace_back(0);
        posToGroup[sortedNums[0]] = 0;
        for (int i = 1; i < n; ++i)
        {
            if (sortedNums[i] - sortedNums[i - 1] <= limit)
            {
                groups.back().emplace_back(sortedNums[i]);
                posToGroup[sortedNums[i]] = groups.size() - 1;
            }
            else
            {
                groups.emplace_back(vector<int>({sortedNums[i]}));
                groupsPtr.emplace_back(0);
                posToGroup[sortedNums[i]] = groups.size() - 1;
            }
        }

        vector<int> res;
        for (int i = 0; i < n; ++i)
        {
            int group = posToGroup[nums[i]];
            res.emplace_back(groups[group][groupsPtr[group]]);
            ++groupsPtr[group];
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {1,5,3,9,8};
    int limit = 2;
    Solution s;
    s.lexicographicallySmallestArray(nums, limit);
    return 0;
}