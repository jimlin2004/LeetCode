#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// isp[i][j] -> s[i ~ j]是否為回文

class Solution
{
public:
    int countSubstrings(string s)
    {
        memset(isp, 0, sizeof(isp));
        int res = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            isp[i][i] = true;
            ++res;
        }
        for (int l = 2; l <= s.size(); ++l)
        {
            for (int i = 0; i + l - 1 < s.size(); ++i)
            {
                int j = i + l - 1;
                if (j - i == 1)
                {
                    isp[i][j] = (s[i] == s[j]);
                }
                else
                {
                    isp[i][j] = (isp[i + 1][j - 1]) && (s[i] == s[j]);
                }
                res += isp[i][j];
            }
        }

        return res;
    }
private:
    bool isp[1005][1005];
};

int main()
{
    Solution s;
    s.countSubstrings("abc");
    return 0;
}