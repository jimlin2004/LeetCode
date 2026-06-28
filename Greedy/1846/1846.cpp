#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    /*
        基本上就是要求 1 ... n最大n能是多少
        然後每個數字可以rearrange還有變成比自己小的數字
        所以直覺想到從小到大排

        然後變成比自己小的數字其實就用一個變數去記錄當前需要的數字
        如果現在currVal <= arr[i]，arr[i]就可以用(或變成需要的新數字)
        如果不行，就往後換下一個人

        這樣就有答案了
    */
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) 
    {
        sort(arr.begin(), arr.end());

        int res = 0;
        int currVal = 1;
        for (int i = 0; i < arr.size(); ++i)
        {
            if (currVal <= arr[i])
            {
                ++res;
                ++currVal;
            }
        }

        return res;
    }
};