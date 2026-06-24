#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

struct Matrix
{
    int m, n;
    vector<vector<int>> vals;

    Matrix(int m, int n)
        : m(m), n(n)
        , vals(m, vector<int>(n))
    {
    }

    Matrix operator*(const Matrix& other) const
    {
        Matrix res(m, other.n);

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < other.n; ++j)
            {
                for (int k = 0; k < n; ++k)
                {
                    long long prod = (1LL* vals[i][k] * other.vals[k][j]) % MOD;
                    res.vals[i][j] = (res.vals[i][j] + prod) % MOD;
                }
            }
        }

        return move(res);
    }
};

/*
解法有參考hint

m = r - l + 1
baseMat shape: (2m, 1)
意義是前m個是(x, down), 後m個是(x, up)

建立轉移矩陣算總數 T shape: (2m, 2m)
將(x, down)加到(y, up)，y > x
將(x, up)加到(y, down)，y < x
做矩陣快速冪

最後將答案的矩陣整個加起來

比如n = 3, l = 1, r = 3
baseMat:
(0, d): 1
(1, d): 1
(2, d): 1
(0, u): 1
(1, u): 1
(2, u): 1

T:
0 0 0 0 1 1 
0 0 0 0 0 1
0 0 0 0 0 0
0 0 0 0 0 0
1 0 0 0 0 0
1 1 0 0 0 0

*/

class Solution
{
private:
    Matrix qpow(Matrix A, int n)
    {
        Matrix res(A.m, A.n);
        // 變成單位矩陣
        for (int i = 0; i < res.m; ++i)
            res.vals[i][i] = 1;
        
        while (n)
        {
            if (n & 1)
                res = res * A;
            A = A * A;
            n >>= 1;
        }

        return move(res);
    }
public:
    int zigZagArrays(int n, int l, int r)
    {
        int m = r - l + 1;

        Matrix baseMat(2 * m, 1);
        for (int i = 0; i < baseMat.m; ++i)
            baseMat.vals[i][0] = 1;

        Matrix T(2 * m, 2 * m);
        // 枚舉 x
        for (int x = 0; x < m; ++x)
        {
            // 將(x, down)加到(y, up), y > x
            for (int y = x + 1; y < m; ++y)
            {
                T.vals[m + y][x] = 1;
            }

            // 將(x, up)加到(y, down)，y < x
            for (int y = 0; y < x; ++y)
            {
                T.vals[y][m + x] = 1;
            }
        }

        Matrix resMat = qpow(T, n - 1) * baseMat;

        int res = 0;
        for (int i = 0; i < resMat.m; ++i)
            res = (res + resMat.vals[i][0]) % MOD;

        return res;
    }
};

int main()
{
    Solution S;
    S.zigZagArrays(3, 1, 3);
}