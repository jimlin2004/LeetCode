#include <vector>
using namespace std;

class Solution 
{
public:
    vector<int> getRow(int rowIndex)
    {
        //滾動陣列
        int d[40] = {0, 1, 0, 0};
        int p[40];
        for (int r = 1; r <= rowIndex; ++r)
        {
            for (int i = 1; i <= r; ++i)
            {
                p[i] = d[i - 1] + d[i];
            }
            p[r + 1] = 1;
            for (int i = 1; i <= r + 1; ++i)
                d[i] = p[i];
        }
        vector<int> res;
        for (int i = 1; i <= rowIndex + 1; ++i)
            res.push_back(d[i]);
        return res;
    }
};

int main()
{
    Solution s;
    s.getRow(3);
}