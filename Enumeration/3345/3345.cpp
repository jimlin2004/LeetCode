class Solution 
{
public:
    int getDigitalProd(int n)
    {
        int res = 1;
        while (n)
        {
            res *= (n % 10);
            n /= 10;
        }

        return res;
    }

    // 水題
    int smallestNumber(int n, int t) 
    {
        for (int i = n; ; ++i)
        {
            if (getDigitalProd(i) % t == 0)
                return i;
        }

        return -1;
    }
};