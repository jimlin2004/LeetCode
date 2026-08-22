class Solution
{
public:
    int getDigitalSum(int n)
    {
        int res = 0;
        while (n > 0)
        {
            res += n % 10;
            n /= 10;
        }
        return res;
    }

    int getDigitalProb(int n)
    {
        int res = 1;
        while (n > 0)
        {
            res *= n % 10;
            n /= 10;
        }
        return res;
    }


    // 水題
    bool checkDivisibility(int n)
    {
        return (n % (getDigitalSum(n) + getDigitalProb(n)) == 0);
    }
};