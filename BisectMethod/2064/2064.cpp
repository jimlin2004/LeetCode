#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    //看看一間商店只能最多分配maxN的情況下，最少要分幾間出來
    int check(vector<int>& quantities, int maxN)
    {
        int cnt = 0;
        for (int i = 0; i < quantities.size(); ++i)
        {
            cnt += quantities[i] / maxN + (quantities[i] % maxN != 0);
        }
        return cnt;
    }
    int minimizedMaximum(int n, vector<int>& quantities) 
    {
        int maxN = -0x3f3f3f3f;
        for (int N: quantities)
            maxN = max(maxN, N);
        //l = 1, r = 最大一種商品有幾個
        int l = 1, r = maxN;
        //對答案二分搜
        while (l < r)
        {
            int mid = (l + r) >> 1;
            //如果最多分mid個商品只要 <= n個商店 -> 看能不能更小
            if (check(quantities, mid) <= n)
                r = mid;
            else
                l = mid + 1; //如果最多分mid個商品需要 > n個商店 -> mid太小
        }
        return l;
    }
};