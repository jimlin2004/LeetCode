#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    // 題目只問是否存在，看數值範圍要O(n)
    // 所以需要推一下性質
    // 可以發現到在建derived的時候
    // 只要設original[0]為0 or 1可以用derived找到一個original
    // 但更快的方法是因為在建立derived的時候每個original的元素
    // 會被用兩次，所以存在性在於整個derived做XOR後應該要等於0
    bool doesValidArrayExist(vector<int>& derived) 
    {
        int res = 0;
        for (int val: derived)
            res ^= val;
        return (res == 0);
    }
};