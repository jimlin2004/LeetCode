#include <vector>
#include <algorithm>
using namespace std;

/*
    想法簡單，當到了格子i時
    只需要保留可以走到最遠的步數即可
*/

class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
        int step = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (step == 0)
                return false;
            --step;
            step = max(step, nums[i]);
        }
        return true;
    }
};