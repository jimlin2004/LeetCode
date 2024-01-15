//binary search 與斜率有關，所以可以用於搜尋peak element
#include <vector>
using namespace std;

class Solution 
{
public:
    int findPeakElement(vector<int>& nums) 
    {
        if (nums.size() == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        else if (nums[nums.size() - 2] < nums[nums.size() - 1])
            return nums.size() - 1;
        int l = 1, r = nums.size() - 2;
        int mid;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
                return mid;
            else if (nums[mid + 1] > nums[mid])
                l = mid + 1;
            else 
                r = mid;
        }
        return -1;
    }
};