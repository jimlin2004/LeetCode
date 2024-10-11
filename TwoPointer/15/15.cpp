#include <vector>
#include <algorithm>
using namespace std;

/*
    解法是用i固定一個數
    i後面的區間就用雙指標法找出j、k
    使nums[i] + nums[j] + nums[k] == 0
    即可
    記得先sort保證雙指標正確
*/

class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
        {
            //去掉重複的不考慮，否則答案會有重複項
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int j = i + 1, k = nums.size() - 1;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0)
                {
                    res.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    --k;
                    //去掉重複的不考慮，否則答案會有重複項
                    while ((j < k) && nums[j] == nums[j - 1])
                        ++j;
                    while ((j < k) && nums[k] == nums[k + 1])
                        --k;
                }
                else if (sum < 0)
                {
                    //sum < 0代表負太大，所以把j右移讓值變大
                    ++j;
                }
                else if (sum > 0)
                {
                    //sum > 0代表正太大，所以把k左移讓值變小
                    --k;
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
    vector<int> vec = {-1,0,1,2,-1,-4};
    s.threeSum(vec);
}