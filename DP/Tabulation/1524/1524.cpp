#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    static const int MOD = 1e9 + 7;
    static const int maxn = 1e3 + 5;

    /*
        類似前綴和(微dp)
        概念是用兩個arr
        dpOdd[i] -> 以i為結束的subarray其和是奇數的
        dpEven[i] -> 以i為結束的subarray其和是偶數的
        當現在arr[i]是
        1. even -> 奇數和的還是奇數，偶數和的還是偶數
        2. odd -> 偶數和的變奇數，奇數和的變偶數
        所以轉移式:
        if (arr[i] & 1)
        {
            dpOdd[i] = dpEven[i - 1] + 1;
            dpEven[i] = dpOdd[i - 1];
        }
        else // even
        {
            dpOdd[i] = dpOdd[i - 1];
            dpEven[i] = dpEven[i - 1] + 1;
        }
        其中的 + 1來自於以i為開頭的subarray，
        在轉移的當下以i為開頭的subarray同時以i為結束

        以這樣的轉移式可以考慮到所有的subarray
        (有起頭有結束，都有考慮到)

        最後再從頭搜一遍把每個位置的dpOdd[i]加起來即為答案
        O(n) + O(n)
    */
    int numOfSubarrays(vector<int>& arr) 
    {
        int dpEven[maxn];
        int dpOdd[maxn];
        
        if (arr[0] & 1)
        {
            dpOdd[0] = 1;
            dpEven[0] = 0;
        }
        else // even
        {
            dpOdd[0] = 0;
            dpEven[0] = 1;
        }

        int n = arr.size();
        for (int i = 1; i < n; ++i)
        {
            if (arr[i] & 1)
            {
                dpOdd[i] = dpEven[i - 1] + 1;
                dpEven[i] = dpOdd[i - 1];
            }
            else // even
            {
                dpOdd[i] = dpOdd[i - 1];
                dpEven[i] = dpEven[i - 1] + 1;
            }
        }

        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            res += dpOdd[i];
            res %= MOD;
        }
        return res;
    }
};

int main()
{
    Solution S;
    vector<int> arr = {100, 100, 99, 99};
    S.numOfSubarrays(arr);
    return 0;
}