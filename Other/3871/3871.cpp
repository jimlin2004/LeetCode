class Solution 
{
public:
    // 水題
    long long countCommas(long long n) 
    {
        long long res = 0;
        if (n > 999)
            res += n - 999; // 1,000以上貢獻一個
        if (n > 999999)
            res += n - 999999; // 1,000,000以上貢獻另一個
        if (n > 999999999L)
            res += n - 999999999L; // 1,000,000,000以上貢獻另一個
        if (n > 999999999999L)
            res += n - 999999999999L; // 1,000,000,000,000以上貢獻另一個
        if (n > 999999999999999L)
            res += n - 999999999999999L; // 1,000,000,000,000,000以上貢獻另一個
        
        return res;
    }
};