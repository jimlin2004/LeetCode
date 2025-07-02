#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    vector<int> cap; // 每個work的工作量

    bool dfs(int idx, vector<int>& jobs, int k, int mostCap)
    {
        if (idx == jobs.size())
            return true; // 分完了
        
        // backtracking嘗試能不能分
        for (int j = 0; j < k; ++j)
        {
            if (cap[j] + jobs[idx] <= mostCap)
            {
                cap[j] += jobs[idx];
                if (dfs(idx + 1, jobs, k, mostCap))
                    return true;
                cap[j] -= jobs[idx];
            }

            // 剪枝
            // 當目前的工作分下去結果前面的工人沒有被分配工作，就代表不可能分完
            // 因為for loop優先分配給前面的工人，不可能選擇跳過前面的人選後面
            if (cap[j] == 0)
                return false;
        }

        return false;
    }

    int minimumTimeRequired(vector<int>& jobs, int k) 
    {
        sort(jobs.rbegin(), jobs.rend()); // 由大到小排，優先將大的工作分出去

        int totalT = 0;
        for (int job: jobs)
            totalT += job;
        
        int l = 0, r = totalT + 1; // l是不能的上界，r是可以的下界
        while (l + 1 < r)
        {
            int mid = (l + r) >> 1;
            cap.assign(k + 5, 0); // 每次要記得清空
            if (dfs(0, jobs, k, mid))
                r = mid;
            else
                l = mid;
        }

        return r;
    }
};


int main()
{
    Solution S;
    vector<int> jobs = {3, 2, 3};
    S.minimumTimeRequired(jobs, 3);

    return 0;
}