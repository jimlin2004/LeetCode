#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
        我覺得不好想的題目，有參考題解

        題意: |word2| = M，要在word1中找出M個indices seq[0], seq[1], ..., seq[M - 1]
        要求:
        1. seq字典序最小
        2. 可以最多修改一次word1的字元

        難點: 字典序要最小，可能會想趕快用到1次修改機會，但太早用可能導致後面無法匹配
        不使用，也可能導致找到的seq字典序不夠小

        因此作法是
        思考 在匹配word2[i]的字元時，能不能使用修改的一次機會，找一個不匹配word2的字元?
        作法是: 要知道選了word2[i]用其他字元修改，剩下的word1後綴還能不能匹配word2的後綴

        為了做到這點，需要預處理後綴資訊
        last[i] -> 要完全匹配word2[i ... M - 1]，在word1中最右邊的起始index是多少
        (詳細作法看下方)

        可以做到O(|word1| + |word2|)
    */
    vector<int> validSequence(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();

        vector<int> last(m, -1);
        int ptr1 = n - 1; // word1的ptr
        for (int i = m - 1; i >= 0; --i)
        {
            while (ptr1 >= 0 && word1[ptr1] != word2[i]) // 配不了
                --ptr1; // 換人試試看
            
            last[i] = ptr1; // 這裡如果都配不到，就會是-1
            if (ptr1 >= 0)
                --ptr1; // 因為配到了，所以要換人
        }

        vector<int> res;
        bool used_change = false; // 是不是已經用掉修改機會了
        ptr1 = 0; // 從word1的第一個字元開始嘗試匹配
        for (int i = 0; i < m; ++i)
        {
            while (ptr1 < n)
            {
                // 剛好匹配，就直接選，因為ptr1是左到右，所以這樣字典序會最小
                if (word1[ptr1] == word2[i])
                {
                    res.emplace_back(ptr1);
                    ++ptr1;
                    break;
                }

                // 字元不能配，但也還沒用過修改機會，並且後面還能匹配完，那就選，這樣字典序會最小
                if (!used_change && (i == m - 1 || ptr1 < last[i + 1]))
                {
                    res.emplace_back(ptr1);
                    used_change = true;
                    ++ptr1;
                    break;
                }

                // 都不行，換人試試看
                ++ptr1;
            }
        }

        // 配不了，無解
        if (res.size() != m)
            return {};
        
        return res;
    }
};