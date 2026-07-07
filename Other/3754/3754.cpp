class Solution 
{
public:
    // 水題
    long long sumAndMultiply(int n)
    {
        long long arr[10];
        int m = 0;
        while (n > 0)
        {
            int last = n % 10;
            if (last != 0)
                arr[m++] = last;
            n /= 10;
        }

        long long res = 0;
        long long prod = 0;
        for (int i = m - 1; i >= 0; --i)
        {
            res = res * 10 + arr[i];
            prod += arr[i];
        }
        return res * prod;
    }
};