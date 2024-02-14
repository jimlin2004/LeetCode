#include <string>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    string baseNeg2(int n) 
    {
        //數學題: 結論 mod(-2)時遇到-1則n加一，餘數變1
        //詳細可看 UVA 11121
        if (n == 0)
            return "0";
        string res = "";
        int mod;
        while (n != 0)
        {
            mod = n % (-2);
            n /= (-2);
            if (mod == -1)
            {
                mod = 1;
                ++n;
            }
            res += to_string(mod);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};