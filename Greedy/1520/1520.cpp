#include <bits/stdc++.h>
using namespace std;

struct Seg
{
    int l, r;
};

class Solution 
{
public:
    /*
        題意:
            從s中挑subtring
            1. 每個substring不能重疊
            2. 如果一個substring中包含字母c，那他就要打包全部的c，不能不選
            3. substring的長度越短越好

        看到這裡大概會想到從枚舉字母下手，因為字母只有26種
        因為條件二的愛屋及烏，首先將每個字母的最左最右邊記下來

        有了字母的邊界後，開始求出每個合法線段
        要怎麼枚舉呢?
        因為每個線段要愛屋及烏，所以每個合法線段一定會有唯一的字母開頭
        所以枚舉字母c
        令一開始l = c的左邊界，r = c的右邊界
        然後掃描[l, r]，看看區間中有沒有字母的左邊界 < l， 
        這時候就代表以字母c為開頭根本不可能是合法線段，可以直接剪枝
        如果字母的右邊界 > r，那r = 該字母的右邊界繼續掃描

        如此會得到 <= 26的合法線段

        之後就是選線段要線段最多且不重疊且總長度最短
        那就是經典greedy問題
        將所有線段以r排序
        貪心的選所有不重疊的
        選的r越早結束，留給後面選擇空間的機會越大
        同時因為是以r排序的選，保證了選出來的線段總長度最短
        因為如果數量一樣且另一個選擇長度更短
        那那個線段的r一定比我選錯的短

        O(26N)

    */
    vector<string> maxNumOfSubstrings(string s) 
    {
        vector<int> L(200, -1); // 字母的左邊界
        vector<int> R(200, -1); // 字母的右邊界

        int n = s.size();

        for (char c = 'a'; c <= 'z'; ++c)
        {
            for (int i = 0; i < n; ++i)
            {
                if (s[i] == c)
                {
                    if (L[c] == -1)
                        L[c] = i; // 第一個遇到的就是左邊界
                    R[c] = i; // 最後一個遇到的是右邊界
                }
            }
        }

        vector<Seg> segs;
        // 枚舉所有合法線段
        for (char c = 'a'; c <= 'z'; ++c)
        {
            int l = L[c];
            int r = R[c];
            if (l == -1)
                continue;

            bool ok = true;

            for (int i = l; i <= r; ++i)
            {
                if (L[s[i]] < l)
                {
                    ok = false;
                    break;
                }
                r = max(r, R[s[i]]);
            }

            if (ok)
                segs.emplace_back(Seg{l, r});
        }

        // greedy選出最多線段
        sort(segs.begin(), segs.end(), [](const Seg& a, const Seg& b) {
            return a.r < b.r;
        });

        vector<string> res;

        int currPos = -1;
        for (int i = 0; i < segs.size(); ++i)
        {
            const Seg& seg = segs[i];

            if (currPos < seg.l)
            {
                res.emplace_back(s.substr(seg.l, seg.r - seg.l + 1));
                currPos = seg.r;
            }
        }

        return res;
    }
};