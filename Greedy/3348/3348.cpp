#include <bits/stdc++.h>
using namespace std;

// 質因數數量
struct Factors
{
    int c2 = 0, c3 = 0, c5 = 0, c7 = 0;

    // 乘上某個位數後的質因數變化
    void prod(int d)
    {
        switch (d)
        {
        case 1:
            break;
        case 2:
            ++c2;
            break;
        case 3:
            ++c3;
            break;
        case 4:
            c2 += 2;
            break;
        case 5:
            ++c5;
            break;
        case 6:
            ++c2;
            ++c3;
            break;
        case 7:
            ++c7;
            break;
        case 8:
            c2 += 3;
            break;
        case 9:
            c3 += 2;
            break;
        default:
            break;
        }
    }
};

class Solution 
{
public:
    /*
        難題，有參考題解

        題意: 找到最小的zero-free的number且要 >= num並且被t整除的，如果沒有，回傳-1
        因為res只能是1 ~ 9的digital組成，且res_prod是res的digital相乘，所以t的質因數不可能有2、3、5、7以外的質數
        這是因為如果11、13、17...這些質數，res_prod不可能被t整除

        因此先判斷t是否可以寫成2^a x 3^b x 5^c x 7^d，
        如果不行就無解，如果可以，保證有解

        再來因為res >= num
        假設|num| = N
        且res要最小，所以有個貪心策略是
        讓左邊的數字盡量跟num一樣，在第i位改比原本更大的數字後，i右邊的數字都可以隨意填(一樣越小越好)
        並且res_prod至少要有a個2、b個3、c個5、d個7
        但是因為res_prod要zero-free，所以如果有0就要優先處理
        因此要看從N - 1開始還是從first_zero開始

        所以假設目前在第i個位置，剩下L個格子可以填數字，還需要a'個2、b'個3、c'個5、d'個7
        一個簡單的剪枝是如果最少需要的格子數 > L，永遠不可能湊的出來

        如果L還夠用
        就要用貪心方法填數字
        1. 有空位時優先填1
        2. 優先把大數字填在右邊

        細節看下方，可以神奇地做到O(N)
    */

    // t <= 10^14 -> 大概有47個2、30個3(用log估算)
    // dp[i][j] -> 需要i個2，j個3的時候最短且字典序最小的字串
    // 需要這個是因為1 ~ 9還是有2跟3的倍數，5、7就不用
    inline static string dp[55][40];
    inline static bool needInitDP = true; // 超級hack，因為leetcode是用重新建立物件的方式

    void initDP()
    {
        if (!needInitDP)
            return;
        needInitDP = false;

        vector<pair<char, pair<int, int>>> digitsPrimeCnt = {
            {'2', {1, 0}}, {'3', {0, 1}}, {'4', {2, 0}},
            {'6', {1, 1}}, {'8', {3, 0}}, {'9', {0, 2}}
        };

        for (int i = 0; i <= 50; ++i)
        {
            for (int j = 0; j <= 35; ++j)
            {
                if (i == 0 && j == 0)
                {
                    dp[i][j] = "";
                    continue;
                }

                string best = string(60, '9'); // 設為最大
                for (auto& d: digitsPrimeCnt)
                {
                    int prev_i = max(0, i - d.second.first);
                    int prev_j = max(0, j - d.second.second);

                    // 沒有改變 -> 跳過
                    if (prev_i == i && prev_j == j)
                        continue;

                    string temp = dp[prev_i][prev_j] + d.first;
                    sort(temp.begin(), temp.end());

                    if (temp.size() < best.size() || (temp.size() == best.size() && temp < best))
                        best = temp;
                }
                dp[i][j] = best;
            }
        }
    }


    string smallestNumber(string num, long long t) 
    {
        Factors needFactors;

        while (t % 2 == 0)
        {
            ++needFactors.c2;
            t /= 2;
        }
        while (t % 3 == 0)
        {
            ++needFactors.c3;
            t /= 3;
        }
        while (t % 5 == 0)
        {
            ++needFactors.c5;
            t /= 5;
        }
        while (t % 7 == 0)
        {
            ++needFactors.c7;
            t /= 7;
        }

        if (t > 1) // 有其他質數
            return "-1";

        initDP();

        int n = num.size();

        // 先檢查原本的num

        // 先算好num個所有前綴能有的質數 (1-based)
        vector<Factors> prefixFactors(n + 1);
        int first_zero = -1;
        for (int i = 0; i < n; ++i)
        {
            if (num[i] == '0' && first_zero == -1)
            {
                first_zero = i;
                break; // 遇到0，後面都不用算了
            }
            prefixFactors[i + 1] = prefixFactors[i];
            prefixFactors[i + 1].prod(num[i] - '0');
        }

        // 檢查num本身是否合法
        if (first_zero == -1 && prefixFactors[n].c2 >= needFactors.c2
            && prefixFactors[n].c3 >= needFactors.c3 && prefixFactors[n].c5 >= needFactors.c5
            && prefixFactors[n].c7 >= needFactors.c7)
            return num;

        int start_i = (first_zero == -1) ? n -1 : first_zero;
        // 從右往左枚舉第i位變大
        for (int i = start_i; i >= 0; --i)
        {
            for (int d = (num[i] - '0') + 1; d <= 9; ++d)
            {
                // 0 ~ i - 1的前綴質因數數量
                Factors currFactors = prefixFactors[i];
                currFactors.prod(d); // 新的數字

                int remain2 = max(0, needFactors.c2 - currFactors.c2);
                int remain3 = max(0, needFactors.c3 - currFactors.c3);
                int remain5 = max(0, needFactors.c5 - currFactors.c5);
                int remain7 = max(0, needFactors.c7 - currFactors.c7);

                // 拿到最好的2、3組合字串
                string best23 = dp[remain2][remain3];
                int minSlotsNeeded = remain5 + remain7 + best23.size(); // 至少需要多少格空位
                int remainSlots = n - 1 - i; // 還剩下多少空位
                if (minSlotsNeeded <= remainSlots)
                {
                    // 記得剩下全部塞1
                    string bestTail = best23 + string(remain5, '5') + string(remain7, '7') +
                        string(remainSlots - minSlotsNeeded, '1');
                    // 讓字典序最小
                    sort(bestTail.begin(), bestTail.end());
                    return num.substr(0, i) + to_string(d) + bestTail;
                }
            }
        }

        // 至此長度為N不夠，需要變長
        string best23 = dp[needFactors.c2][needFactors.c3];
        int minSlotsNeeded = needFactors.c5 + needFactors.c7 + best23.size();
        int newLen = max(n + 1, minSlotsNeeded); // 要嘛多一個，要嘛多很多，n + 1是為了比num大
        string ans = best23 + string(needFactors.c5, '5') + string(needFactors.c7, '7') + string(newLen - minSlotsNeeded, '1');
        sort(ans.begin(), ans.end());
        return ans;
    }
};