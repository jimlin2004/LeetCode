#include <bits/stdc++.h>
using namespace std;

struct ClassItem
{
    double gain;

    int pass;
    int total;

    ClassItem(int pass, int total)
    {
        this->pass = pass;
        this->total = total;
        this->gain = (1.0 * (this->pass + 1) / (this->total + 1)) - (1.0 * this->pass) / this->total;
    }

    bool operator < (const ClassItem& other) const
    {
        return gain < other.gain;
    }
};

class Solution
{
public:
    /*
        解題方式很簡單
        首先觀察到如果原本就能夠全過
        再補上人還是全過，不會改善平均通過率

        然後觀察對於一個班級來說 pass / total (pass < total)
        同時pass以及total一起增加的時候pass / total會越來越接近1
        這也說明pass與total越來越接近1時進步幅度會越來越少(不然不會收斂到1)
        上述的證明有點複雜，這裡跳過

        所以做法就是用pq每次挑進步幅度最大的出來加一
        最後答案算一下即可

        O(nlogn)
    */
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents)
    {
        priority_queue<ClassItem> pq;

        for (vector<int>& classInfo: classes)
            pq.push(ClassItem(classInfo[0], classInfo[1]));
        
        while (extraStudents--)
        {
            ClassItem classItem = pq.top();
            pq.pop();
            pq.push(ClassItem(classItem.pass + 1, classItem.total + 1));
        }

        double res = 0;
        while (!pq.empty())
        {
            ClassItem classItem = pq.top();
            pq.pop();

            res += 1.0 * classItem.pass / classItem.total;
        }

        return res / classes.size();
    }
};


int main()
{
    vector<vector<int>> classes = {{1,2},{3,5},{2,2}};
    Solution S;
    S.maxAverageRatio(classes, 2);

    return 0;
}