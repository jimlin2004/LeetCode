#include <vector>
#include <cstdlib>
using namespace std;

class Solution 
{
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries)
    {
        vector<int> res;
        for (int i = 0; i < queries.size(); ++i)
        {
            int count = 0;
            double dis = 0;
            for (int j = 0; j < points.size(); ++j)
            {
                dis = this->getDis(queries[i][0], queries[i][1], points[j][0], points[j][1]);
                if (abs(dis - queries[i][2]) < this->eps || dis < queries[i][2])
                    ++count;
            }
            res.emplace_back(count);
        }
        return res;
    }
private:
    const double eps = 1e-6;
    inline double getDis(int x1, int y1, int x2, int y2)
    {
        return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }
};