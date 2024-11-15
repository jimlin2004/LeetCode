#include <bits/stdc++.h>
using namespace std;

/*
    用UVA k sum的解法就行了
*/

struct Item
{
    int sum;
    int index;

    bool operator < (const Item& other) const
    {
        return sum > other.sum;
    }
};

class Solution 
{
public:
    void solve(int A[], int B[], int C[], int n, int k)
    {
        priority_queue<Item> pq;
        for (int i = 0; i < k; ++i)
            pq.push({A[i] + B[0], 0});
        for (int i = 0; i < k; ++i)
        {
            Item item = pq.top();
            pq.pop();
            C[i] = item.sum;
            if (item.index + 1 == n)
                continue;
            item.sum -= B[item.index];
            item.sum += B[item.index + 1];
            item.index += 1;
            pq.push(item);
        }
    }

    int kthSmallest(vector<vector<int>>& mat, int k)
    {
        int A[205] = {};
        int B[205] = {};
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));

        int m = mat.size();
        int n = mat[0].size();
        if (m == 1)
        {
            return mat[0][k - 1];
        }
        for (int i = 0; i < n; ++i)
        {
            A[i] = mat[0][i];
            B[i] = mat[1][i];
        }

        //第一、二行要特別處理
        priority_queue<Item> pq;
        for (int i = 0; i < n; ++i)
            pq.push({A[i] + B[0], 0});
        for (int i = 0; i < k; ++i)
        {
            //因為第一、二行可能湊不出k個，所以填入0x3f3f3f3f
            if (i >= n * n)
            {
                A[i] = 0x3f3f3f3f;
                continue;
            }
            Item item = pq.top();
            pq.pop();
            A[i] = item.sum;
            if (item.index + 1 == n)
                continue;
            item.sum -= B[item.index];
            item.sum += B[item.index + 1];
            item.index += 1;
            pq.push(item);
        }
        
        for (int i = 2; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                B[j] = mat[i][j];
            }
            solve(A, B, A, n, k);
        }
        return A[k - 1];
    }
};

int main()
{
    vector<vector<int>> vec = {{1,10,10},{1,4,5},{2,3,6}};
    int k = 27;
    Solution s;
    s.kthSmallest(vec, k);
}