#include <bits/stdc++.h>
using namespace std;


class Solution 
{
private:
    bool isP[25][25];
public:
    // 建迴文表之後backtracking
    vector<vector<string>> partition(string s)
    {
        memset(isP, 0, sizeof(isP));

        int n = s.size();

        for (int l = 1; l <= n; ++l)
        {
            for (int i = 0; i + l - 1 < n; ++i)
            {
                int j = i + l - 1;
                if (l == 1)
                    isP[i][j] = true;
                else if (l == 2)
                    isP[i][j] = (s[i] == s[j]);
                else
                    isP[i][j] = (isP[i + 1][j - 1] && (s[i] == s[j]));
            }
        }

        vector<vector<string>> res;
        this->dfs(s, 0, res);

        return res;
    }

    void dfs(const string& s, int i, vector<vector<string>>& res)
    {
        static vector<string> vec;

        if (i >= s.size())
        {
            res.emplace_back(vec);
            return;
        }

        for (int l = 1; i + l - 1 < s.size(); ++l)
        {
            int j = i + l - 1;
            if (isP[i][j])
            {
                vec.emplace_back(s.substr(i, l));
                dfs(s, j + 1, res);
                vec.pop_back();
            }
        }
    }
};


int main()
{
    Solution S;
    S.partition("aab");
    return 0;
}