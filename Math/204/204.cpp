#include <math.h>
#include <vector>
using namespace std;

class Solution 
{
public:
    int countPrimes(int n) 
    {
        //埃氏篩法
        vector<bool> tabel(n + 1, true);
        int count = 0;
        tabel[0] = tabel[1] = false;
        for (int i = 2; i * i <= n; i++)
        {
            if (tabel[i])
            {
                for (int j = i * i; j <= n; j += i)
                    tabel[j] = false;
            }
        }
        for (int i = 2; i < n; i++)
        {
            if (tabel[i])
                count++;
        }
        return count;
    }
};

int main()
{
    Solution s;
    s.countPrimes(10);
}