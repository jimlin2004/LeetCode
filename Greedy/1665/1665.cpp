#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:

    bool check(vector<vector<int>> tasks, int E)
    {
        for (auto& task: tasks)
        {
            if (E < task[1])
                return false;
            E -= task[0];
        }

        return true;
    }

    int minimumEffort(vector<vector<int>>& tasks) 
    {
        /*
            這裡的greedy有點反直覺
            greedy方法是利用min - actual
            概念是這樣的方法能夠將那些能夠先存下最多能量的任務先做完
        */

        sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] - a[0] > b[1] - b[0];
        });

        // 其實這裡可以用計算的方式O(n)
        int totalE = 0;
        for (auto& task: tasks)
            totalE += task[1];

        int L = 0, R = totalE + 1;

        while (L + 1 < R)
        {
            int mid = (L + R) >> 1;
            if (!check(tasks, mid))
                L = mid;
            else
                R = mid;
        }

        return R;
    }
};


int main()
{
    Solution S;
    vector<vector<int>> tasks = {{1,2},{2,4},{4,8}};
    S.minimumEffort(tasks);
}