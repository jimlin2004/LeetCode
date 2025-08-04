#include <bits/stdc++.h>
using namespace std;


#define maxn 200005

class Solution 
{
public:
    int prefix[maxn];
    
    /*
        基本上由於只要走過就能夠全拿
        然後有限制步數k
        所以只有4種可能
        一路往右
        一路往左
        先往右在往左
        先往左再往右
        這四種答案取最好的即可

        沒有道理要走一段換方向再走一段
    */
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) 
    {
        memset(prefix, 0, sizeof(prefix));

        int n = fruits.size();

        // prefix座標往右1格
        ++startPos;

        for (vector<int>& fruit: fruits)
        {
            prefix[fruit[0] + 1] += fruit[1];
        }

        for (int i = 1; i < maxn; ++i)
        {
            prefix[i] += prefix[i - 1];
        }

        int res = 0;
        // 一路往右
        res = prefix[min(startPos + k, maxn - 1)] - prefix[startPos - 1];
        // 一路往左
        res = max(res, prefix[startPos] - prefix[max(0, startPos - k - 1)]);
        // 往右再往左
        for (int moveRight = 1; moveRight <= k; ++moveRight)
        {
            int rightPos = startPos + moveRight;
            int moveLeft = k - 2 * moveRight;
            
            if (moveLeft <= 0) // 已經等於一路往右
                break;
            if (rightPos >= maxn)
                break;

            int leftPos = max(1, startPos - moveLeft);

            res = max(res, (prefix[rightPos] - prefix[leftPos - 1]));
        }
        // 往左再往右
        for (int moveLeft = 1; moveLeft <= k; ++moveLeft)
        {
            int leftPos = startPos - moveLeft;
            int moveRight = k - 2 * moveLeft;
            
            if (moveRight <= 0) // 已經等於一路往左
                break;
            if (leftPos < 1)
                break;

            int rightPos = min(maxn - 1, startPos + moveRight);

            res = max(res, (prefix[rightPos] - prefix[leftPos - 1]));
        }

        return res;
    }
};


int main()
{
    vector<vector<int>> F = {{0,15},{3,56},{4,98},{5,81},{7,16},{8,77},{9,89},{12,82},{13,49},{14,59},{17,40},{18,83},{19,35},{20,31},{21,44},{22,92},{25,84},{26,42},{29,4},{33,78},{35,83},{36,3},{37,71},{41,24},{44,81},{45,35},{46,81},{48,81},{50,85},{52,32},{53,93},{54,89},{55,82},{56,60},{59,52},{62,79},{63,90},{64,41},{66,15},{68,43},{69,32},{70,51},{71,79},{75,39},{76,21},{78,16},{79,44},{80,73},{81,95},{83,95},{85,11},{87,80},{88,2},{90,89},{99,35},{100,95}};
    Solution S;
    S.maxTotalFruits(F, 86, 107);
    return 0;
}