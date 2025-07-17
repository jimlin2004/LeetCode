#include <bits/stdc++.h>
using namespace std;


/*
    很難的題
    以下是參考自官方解法
    首先定一個函式F(n, f, s)代表n個人且firstPlayer的位置在f，secondPlayer的位置在s
    然後注意到一些性質
    1. F(n, f, s) = F(n, s, f) <- 直覺
    2. F(n, f, s) = F(n, n + 1 - s, n + 1 - f) -> 因為第i個人跟第-i個人比賽，所以整個相反不會有影響
    有這兩個結果後我們可以永遠保持f在s的左邊

    定義dp轉移式
    因為能夠保持f在s的左邊
    所以有三種case，也就是s在左半、中間、右半

    1. s在左半
        ....      f      ....      s ....  中間 ......
    [有f - 1人]     [有s - f - 1人]
    此時那f - 1個人以及s - f - 1個人分別會去與右半邊的人比賽
    所以我們要枚舉 f - 1個人剩下i個人贏 以及 s - f - 1個人剩下j個人贏 的情況
    這些情況下f與s的位置會變成i + 1以及i + j + 2
    因此F(n, f, s) = min(F(下高斯[(n + 1) / 2], i + 1, i + j + 2)) + 1 for all 合法的i與j

    2. s在中間
        ....      f      ....           s 
    [有f - 1人]     [有s - f - 1人]   [是中間]
    幸運的是，s在中間的情況跟s在左邊的轉移式一模一樣

    3. s在右半
    首先當f + s == n + 1時，f與s會在這一輪對決 -> F(n, f, s) = 1

    這裡要多討論一個s' = n + 1 - s
    如
        ....     f     ....      s' ....  中間 .....  s
    [有f - 1人]   [有s' - f - 1人]
    有兩個額外的情況
    f > s'以及f < s'
    但是由於F(n, f, s) = F(n, n + 1 - s, n + 1 - f)
    所以只要將f換到n + 1 - s以及將s換到n + 1 - f的位置
    此時f < s且f < s'
    所以事實上只需要討論f < s'的例子
    
    s'與s之間有n - 2s'個人，若n - 2s'是even，會剩下(n - 2s') / 2個人
    若n - 2s'是odd，會剩下(n - 2s' + 1) / 2個人 <- 因為中間那個人會自動晉級
    所以數學上可以用 下高斯[(n - 2s' + 1) / 2]表示剩下的人數

    一樣我們還需要枚舉f - 1個人會剩下i個人
    以及s' - f - 1個人會剩下j個人
    此時f與s的位置會變成i + 1以及i + j + 下高斯[(n - 2s' + 1) / 2] + 2
    所以dp轉移式為
    F(n, f, s) = min(F(下高斯[n + 1 / 2], i + 1, i + j + 下高斯[(n - 2s' + 1) / 2] + 2)) + 1

    最後由於我們需要知道最少與最多的輪數
    所以用兩個dp表格紀錄
    F[n][f][s]紀錄最少
    G[n][f][s]紀錄最多

    詳細程式看下方
    dp有O(n ^ 2 * logn)個狀態，每個狀態需要枚舉i與j才能轉移
    所以複雜度是O(n ^ 4 * logn)

*/

class Solution 
{
public:
    int F[30][30][30];
    int G[30][30][30];

    pair<int, int> dp(int n, int f, int s)
    {
        if (F[n][f][s] != -1)
            return {F[n][f][s], G[n][f][s]};
        
        if  (f + s == n + 1) // 一定在這一場相遇
            return {1, 1};
        
        // F(n, f, s) == F(n, n + 1 - s, n + 1 - f)
        if (f + s > n + 1)
        {
            auto res = dp(n, n + 1 - s, n + 1 - f);
            F[n][f][s] = res.first;
            G[n][f][s] = res.second;
            return {F[n][f][s], G[n][f][s]};
        }

        int earliest = 0x3f3f3f3f;
        int latest = -0x3f3f3f3f;
        int half = (n + 1) / 2;

        if (s <= half) // s在左半或中間
        {
            for (int i = 0; i < f; ++i)
            {
                for (int j = 0; j < s - f; ++j)
                {
                    auto res = dp(half, i + 1, i + j + 2);
                    earliest = min(earliest, res.first);
                    latest = max(latest, res.second);
                }
            }
        }
        else
        {
            // s在右半
            int sPrime = n + 1 - s;
            int mid = (n - 2 * sPrime + 1) / 2;
            for (int i = 0; i < f; ++i)
            {
                for (int j = 0; j < sPrime - f; ++j)
                {
                    auto res = dp(half, i + 1, i + j + mid + 2);
                    earliest = min(earliest, res.first);
                    latest = max(latest, res.second);
                }
            }
        }

        F[n][f][s] = earliest + 1;
        G[n][f][s] = latest + 1;
        return {F[n][f][s], G[n][f][s]};
    }

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer)
    {
        memset(F, -1, sizeof(F));
        memset(G, -1, sizeof(G));

        // 讓f永遠在s的左邊
        // 因為F(n, f, s) == F(n, s, f)
        if (firstPlayer > secondPlayer)
            swap(firstPlayer, secondPlayer);
        
        auto res = dp(n, firstPlayer, secondPlayer);
        return {res.first, res.second};
    }
};