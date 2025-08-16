#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 找到最左邊的6然後給他+3就行了
    int maximum69Number (int num)
    {
        int temp = num;
        
        int mostLeaf6 = -1;

        for (int i = 0; temp > 0; temp /= 10, ++i)
        {
            if (temp % 10 == 6)
                mostLeaf6 = i;
        }

        // 算要加多少
        int add = 0;
        if (mostLeaf6 != -1)
        {
            add = 3;
            for (int i = 0; i < mostLeaf6; ++i)
                add *= 10;
        }

        return num + add;
    }
};