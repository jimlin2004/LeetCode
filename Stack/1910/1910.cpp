#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    bool check(vector<char> sk, const string& part)
    {
        //倒序檢查
        if (sk.size() < part.size())
            return false;
        for (int i = sk.size() - 1, j = part.size() - 1; i >= 0 && j >= 0; --i, --j)
        {
            if (sk[i] != part[j])
                return false;
        }
        return true;
    }

    // 暴力檢查，可以用KMP優化，但懶
    string removeOccurrences(string s, string part) 
    {
        // 用vector模擬stack
        vector<char> sk;
        int n = s.size();
        int m = part.size();
        for (int i = 0; i < n; ++i)
        {
            sk.push_back(s[i]);
            // 出現匹配，把字刪掉
            if (check(sk, part))
            {
                for (int j = 0; j < m; ++j)
                    sk.pop_back();
            }
        }

        string res = "";
        for (char c: sk)
            res += c;
        return res;
    }
};

int main()
{
    string s = "kpygkivtlqoockpygkivtlqoocssnextkqzjpycbylkaondsskpygkpygkivtlqoocssnextkqzjpkpygkivtlqoocssnextkqzjpycbylkaondsycbylkaondskivtlqoocssnextkqzjpycbylkaondssnextkqzjpycbylkaondshijzgaovndkjiiuwjtcpdpbkrfsi";
    string part = "kpygkivtlqoocssnextkqzjpycbylkaonds";
    Solution S;
    S.removeOccurrences(s, part);
}