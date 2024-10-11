#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    long long maximumTotalSum(vector<int>& maximumHeight)
    {
        //將maximumHeight由大排到小
        //由於塔的高度不能大於maximumHeight[i]
        //所以只能最大到maximumHeight[i]
        //而塔的高度不能一樣
        //所以塔的高度還有個限制是最高只能是上一個塔的高度 - 1
        //另外要判斷是不是蓋不了

        sort(maximumHeight.begin(), maximumHeight.end(), greater<int>());

        long long res = 0;
        int curr = 0x3f3f3f3f;
        for (int i = 0; i < maximumHeight.size(); ++i)
        {
            if (curr <= 0)
            {
                curr = -0x3f3f3f3f;
                break;
            }
            curr = min(curr, maximumHeight[i]);
            res += curr;
            --curr;
        }
        if (curr == -0x3f3f3f3f)
            return -1;
        return res;
    }
};