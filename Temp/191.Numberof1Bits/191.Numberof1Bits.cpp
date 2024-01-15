#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int hammingWeight(uint32_t n) 
    {
        int res = 0;
        for (int i = 0; i < 32; i++)
        {
            if ((n & 1) > 0)
                res++;
            n >>= 1;
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.hammingWeight(00000000000000000000000000001011);
    system("pause");
}