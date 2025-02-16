#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    bool dfs(int index, int n, bool used[], vector<int>& res)
    {
        // 找到了
        if (index == res.size())
            return true;
        // 這一格被填過數字了，直接換下一格
        if (res[index] != 0)
        {
            return dfs(index + 1, n, used, res);
        }
        // 從大的數字開始填，讓找到的第一個是字典序最大的
        for (int i = n; i >= 2; --i)
        {
            if (used[i])
                continue;
            // 如果在index + i可以填
            if ((index + i < res.size()) && (res[index + i] == 0))
            {
                // 這一格跟index + i格都填i
                res[index] = i;
                res[index + i] = i;
                used[i] = true;
                if (dfs(index + 1, n, used, res))
                    return true;
                // 失敗，變回沒填
                res[index] = 0;
                res[index + i] = 0;
                used[i] = false;
            }
        }
        // 嘗試放1
        if (!used[1])
        {
            res[index] = 1;
            used[1] = true;
            if (dfs(index + 1, n, used, res))
                return true;
            res[index] = 0;
            used[1] = false;
        }
        return false;
    }

    /*
        暴搜，用backtracking
        但是不能一格一格填
        在填的時候看與之前填的數字index - pos[i] == i
        這樣的方式也能找到答案
        但會超時

        要加入一點點Heuristic
        若i沒被用過
        且答案一定需要有另一個i在index + i的位置
        因此若要在這一格填i的時候
        先檢查index + i能不能填i
        這樣的方式能夠比上面的方式還要快
    */
    vector<int> constructDistancedSequence(int n) 
    {
        // 答案長度為2 * n - 1
        vector<int> res(2 * n - 1, 0);
        bool used[25];
        memset(used, 0, sizeof(used));
        dfs(0, n, used, res);
        return res;
    }
};

int main()
{
    Solution S;
    auto res = S.constructDistancedSequence(5);
    return 0;
}