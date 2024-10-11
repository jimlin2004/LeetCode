#include <vector>
#include <string>
#include <cstring>
using namespace std;

class Solution 
{
public:
    //以下做法O(n ^ 2)
    //事實上有O(n)的解法，但需要理解數學證明(Cantor's diagonal argument)
    //長度為 n 的位元組只有 n 個時，只要任意找一個位元與其相反，組成的位元串必定不會跟該字串相同，這樣就能保證一次就找到不同的
    string findDifferentBinaryString(vector<string>& nums)
    {
        int n = nums.size();
        bool seen[(1 << 16) + 5];
        memset(seen, 0, sizeof(seen));
        for (string& num: nums)
        {
            int toNum = 0;
            for (int i = num.size() - 1; i >= 0; --i)
            {
                toNum = (toNum) * 2 + (num[i] - '0');
            }
            seen[toNum] = true;
        }

        string res = "";
        //枚舉沒出現過的數字
        //n個數字，只要枚舉n + 1個數字就一定找的到
        for (int i = 0; i <= n; ++i)
        {
            if (!seen[i])
            {
                for (int j = 0; j < n; ++j)
                {
                    res += (i % 2) + '0';
                    i >>= 1;
                }
                break;
            }
        }
        return res;
    }
};