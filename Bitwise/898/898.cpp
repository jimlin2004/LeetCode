#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    /*
        概念從暴力解而來
        最簡單的方法是每次都計算所有的A[i] | A[i + 1] | ... | A[j]
        這樣要O(N^2)
        同時設定B[i][j] = A[i] | A[i + 1] | ... | A[j]
        上面的可以寫成遞迴式 B[i][j + 1] = B[i][j] | A[j + 1]
        但還是要O(N^2)

        然而事實上不會那麼糟糕
        因為or的操作是遞增的
        也就是說B[0][i] >= B[1][i] >= B[2][i] >= ... >= B[i][i]
        由於數字範圍內只有32個bits
        所以如果用set來儲存B[j][i]的話
        那個set裡最多只會有32個數字存在

        因此只要利用set維護B[j][i]
        每次有新的B[j][i + 1]時
        我們最多只會更新32次答案

        所以事實上複雜度可以降到 O(32N * log 32)
        log 32是set的操作時間
    */
    int subarrayBitwiseORs(vector<int>& arr)
    {
        set<int> res;

        // 設定B[i][j] = A[i] | A[i + 1] | ... | A[j]
        // 用set儲存所有B[0][i], B[1][i], B[2][i], ..., B[i][i]
        set<int> curr;

        set<int> curr2;

        // 迭代B[j][i]的i
        for (int newVal: arr)
        {
            curr2.insert(newVal);

            // 算新的B[j][i + 1]
            for (int B: curr)
                curr2.insert(newVal | B);
            
            curr = move(curr2);

            for (int val: curr)
                res.insert(val);
        }

        return res.size();
    }
};


class Solution 
{
public:
    /*
        unordered_set版本
        只快一點點
    */
    int subarrayBitwiseORs(vector<int>& arr)
    {
        unordered_set<int> res;

        // 設定B[i][j] = A[i] | A[i + 1] | ... | A[j]
        // 用set儲存所有B[0][i], B[1][i], B[2][i], ..., B[i][i]
        unordered_set<int> curr;

        unordered_set<int> curr2;

        // 迭代B[j][i]的i
        for (int newVal: arr)
        {
            curr2.insert(newVal);

            // 算新的B[j][i + 1]
            for (int B: curr)
                curr2.insert(newVal | B);
            
            curr = move(curr2);

            for (int val: curr)
                res.insert(val);
        }

        return res.size();
    }
};