#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // 利用公式: 先轉置，然後每個row reverse
    void rotate90(vector<vector<int>>& mat)
    {
        int n = mat.size();

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                swap(mat[i][j], mat[j][i]);
            }
        }

        // 每個row reverse
        for (auto& row: mat)
            ranges::reverse(row);
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (mat == target)
                return true;
            rotate90(mat);
        }

        return false;
    }
};