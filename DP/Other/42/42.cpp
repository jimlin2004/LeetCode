#include <vector>
#include <algorithm>
using namespace std;

/*
    很簡單，就是紀錄每個位置左邊以(包含自己)來與右邊以來(包含自己)的最高點
    之後min(L[i], R[i]) - height[i]即可
*/
class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();
        vector<int> L(n), R(n);
        L[0] = height[0];
        R[n - 1] = height[n - 1];
        for (int i = 1; i < n; ++i)
            L[i] = max(L[i - 1], height[i]);
        for (int i = n - 2; i >= 0; --i)
            R[i] = max(R[i + 1], height[i]);
        int res = 0;
        for (int i = 0; i < n; ++i)
            res += min(L[i], R[i]) - height[i];
        
        return res;
    }
};