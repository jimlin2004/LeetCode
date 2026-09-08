class Solution 
{
public:
    // 水題
    int countCommas(int n) 
    {
        int res = 0;

        // 最多10^5
        // 1,000以上有一個
        if (n > 999)
            res += (n - 999); // 每個數字貢獻一個,
        
        return res;
    }
};