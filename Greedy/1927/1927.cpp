#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    /*
        不好想，是數學 + greedy的題目，有參考題解

        題意:
            Alice跟Bob可以將num中的?變成0 ~ 9的數字
            Bob要贏只有前一半num的和 == 後一半num的和
        題解:
        num拆成兩半
        1. sumL、sumR代表前後半的和
        2. cntL、cntR代表前後半的各自?有幾個

        由於Alice跟Bob都以最佳策略遊玩
        Alice先動，導致Bob處於被動

        (下方不能用abs，否則會失去哪邊比較大的方向性)

        因此Bob為了保證遊戲能夠贏，只能做
        1. 先做左右對消
        Alice在一邊填d，Bob也在另一半填d
        使兩邊增加的量一樣
        至此可以算出左邊剩下的?是 diff_cnt = cntL - cntR
        2. 剩下一邊有?
        a. 如果diff_cnt是奇數
        此時Alice會比Bob多下一手，Alice一定有辦法讓左右和不同，Bob必輸
        b. 如果diff_cnt是偶數
        由於Bob處於被動，Bob想讓左右相等，能夠做的只有讓左右兩邊互補
        Alice填上d，Bob就填上9 - d
        如此每一輪固定的總和只能是9
        才能固定唯一的結果為
        (diff_cnt / 2) * 9

        因此Bob唯一獲勝的條件只有當(sumL - sumR) + (diff_cnt / 2) * 9 == 0
        
        注意上面的條件已經處理方向性
        如果diff_cnt > 0 -> 此時處理sumL - sumR < 0
        如果diff_cnt < 0 -> 此時處理sumL - sumR > 0
    */
    bool sumGame(string num) 
    {
        int n = num.size();

        int sumL = 0;
        int cntL = 0;
        for (int i = 0; i < n / 2; ++i)
        {
            if (num[i] == '?')
                ++cntL;
            else
                sumL += num[i] - '0';
        }

        int sumR = 0;
        int cntR = 0;
        for (int i = n / 2; i < n; ++i)
        {
            if (num[i] == '?')
                ++cntR;
            else
                sumR += num[i] - '0';
        }

        int diff_cnt = cntL - cntR;

        if (abs(diff_cnt) & 1)
            return true;

        return (sumL - sumR) + (diff_cnt / 2 * 9) != 0;
    }
};