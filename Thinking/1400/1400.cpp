#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    /*
        思維題
        看到數值範圍就知道，只能O(n)或O(nlogn)之類的 [s.size <= 1e5, k <= 1e5]
        基本迴文演算法都不能用
        同時這題要的是使用所有的字元屬於s
        所以文字的順序不被考慮
        自然可以想到要數s中字元的數量
        接下來就是數學與思維了
        1. s.size < k 一定不可能，將s每個字拆開來都不夠
        2. s.size == k 剛好可以組成k個都一個字的迴文字串
        3. 迴文要嘛是都每個字元都even要嘛中間多一個字元
            迴文也可以一個字組成，因此若有k種字元屬於s只有odd個
            最少需要組成k個迴文字串才能用完s的全部字元
            另外
            even個的字元不需要被考慮
            因為我們可以將那even的字元分成....x....與...x...或是都放到一個字串...x..x...
            所以對於even個的字元我們一定可以找到方法分配(可以沒分配)到每個字串中
            這也保證只要處理好odd個就能夠完全將s的字元用完
            得到結論
            只要odd的字元種類 <= s.size 就一定可以組成k個迴文字串
    */
    bool canConstruct(string s, int k) 
    {
        if (s.size() < k)
            return false;

        int cnt[30];
        memset(cnt, 0, sizeof(cnt));
        for (char c: s)
            ++cnt[c - 'a'];
        int oddCnt = 0;
        for (int i = 0; i < 26; ++i)
        {
            if (cnt[i] & 1)
                ++oddCnt;
        }
        return oddCnt <= k;
    }
};