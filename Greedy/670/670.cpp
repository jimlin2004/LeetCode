#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    //greedy題
    //數字越大且越後面放到越前面答案會越大
    //所以統計每個數字最後出現在哪個位置
    //若可以將數字換過去時
    //由於從9開始搜，所以一定第一次交換就是最好的答案
    int maximumSwap(int num) 
    {
        string N = to_string(num);
        int lastPos[10]; //記每個數字最後出現在哪裡
        for (int i = 0; i < N.size(); ++i)
            lastPos[N[i] - '0'] = i;
        for (int i = 0; i < N.size(); ++i)
        {
            for (int d = 9; d > (N[i] - '0'); --d)
            {
                if (lastPos[d] > i)
                {
                    swap(N[i], N[lastPos[d]]);
                    return stoi(N);
                }
            }
        }
        return num;
    }
};