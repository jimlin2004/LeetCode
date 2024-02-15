#include <unordered_map>
using namespace std;

class Solution 
{
public:
    bool isHappy(int n) 
    {
        int square[] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};
        unordered_map<int, bool> mp;
        while (1)
        {
            if (n == 1)
                return true;
            int temp = 0;
            while (n > 0)
            {
                temp += square[n % 10];
                n /= 10;
            }
            if (mp.find(temp) == mp.end())
            {
                mp[temp] = true;
                n = temp;
            }
            else
                return false;
        }
        return false;
    }
};