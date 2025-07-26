#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    /*
        首先觀察
        給定(i, j)的衝突pair時
        若當前的subarray [l, r]是合法的只有沒有任何一個l <= i且j <= r的(i, j) pair存在
        
        所以如果我們枚舉以r為結尾的subarray時
        重要的是找到在j <= r的那些pairs哪個(i, j)的i離r最靠近
        此時已r為結尾的subarray數量有 r - 最靠近的i 個

        以上的解法已經可以解決「不能拿掉衝突pair」時的subarray總數

        但是題目要拿掉一個
        所以我們變成枚舉r時除了維護最靠近的i時還要維護第二靠近的i'
        也就是當我們拿掉最靠近的i那個pair時我們能夠增加的subarray數量為 i - i'個

        因此我們維護當拿掉最靠近的i那個pair時我們能賺到的subarray數量為bonus[最靠近的i]

        所以最後答案就是 「不能拿掉衝突pair」時的subarray總數 + max{bonus}

        O(n + pair數)
    */

    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs)
    {
        // left[j] = {i1, i2, i3, ...} -> 以j為pair尾的i收集起來
        vector<vector<int>> left(n + 5);

        for (auto& p: conflictingPairs)
        {
            // 讓p[0]永遠比較小
            if (p[0] > p[1])
                swap(p[0], p[1]);
            left[p[1]].emplace_back(p[0]);
        }

        //「不能拿掉衝突pair」時的subarray總數
        long long res = 0;

        // 最靠近的i
        int closest = 0;
        // 第二靠近的i'
        int secondClosest = 0;

        vector<long long> bonus(n + 5, 0);

        // 枚舉所有以r為結束的subarray
        for (int r = 1; r <= n; ++r)
        {
            for (int l: left[r])
            {
                // 以r為subarray結尾時維護當前最靠近的i及第二靠近的i'
                if (l > closest)
                {
                    secondClosest = closest;
                    closest = l;
                }
                else if (l > secondClosest)
                {
                    secondClosest = l;
                }
            }

            res += r - closest;

            if (closest > 0)
                bonus[closest] += closest - secondClosest;
        }

        return res + *max_element(bonus.begin(), bonus.end());
    }
};