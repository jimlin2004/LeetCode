#include <bits/stdc++.h>
using namespace std;


class Solution 
{
public:

    // left[i][j] -> 在第i個row的第j個col左邊(包含)有連續多少個1
    int left[155][155];

    /*
        枚舉的方式
        基本上是用(i, j)作為右下角去數他能夠做出多少個矩形
        方法是預處理的left[i][j]知道每個點那一排的左邊有多少個連續的1
        如此枚舉能夠透過枚舉矩形的高度k
        做法是以(i, j)為右下角的矩形在i那個row有left[i][j]個
        在i ~ i - 1那個row有min(left[i][j], left[i - 1][j])個矩形
        所以一路枚舉row k -> 有min(left[i][j], left[i - 1][j], ..., left[k][j])個矩形
        然後全部加起來就是(i, j)為右下角能夠有多少種矩形

        並且這種作法還要枚舉所有的(i, j)
        所以是O(m ^ 2 * n) -> 危險
    */
    int numSubmat(vector<vector<int>>& mat)
    {
        memset(left, 0, sizeof(left));

        int m = mat.size();
        int n = mat[0].size();

        int res = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (j == 0)
                    left[i][j] = mat[i][j]; // 是0 or 1
                else
                {
                    if (mat[i][j] == 0)
                        left[i][j] = 0;
                    else
                        left[i][j] = left[i][j - 1] + 1; // 繼續數有多少個1
                }

                int currWidth = left[i][j];
                for (int k = i; k >= 0; --k)
                {
                    currWidth = min(currWidth, left[k][j]);
                    if (currWidth == 0)
                        break;
                    res += currWidth;
                }
            }
        }

        return res;
    }
};



class Solution 
{
public:

    int numSubmat(vector<vector<int>>& mat)
    {
        int m = mat.size();
        int n = mat[0].size();

        // 直方圖高度
        vector<int> height(n + 5, 0);

        int res = 0;

        for (int i = 0; i < m; ++i)
        {
            // 更新直方圖高度
            for (int j = 0; j < n; ++j)
            {
                if (i == 0)
                    height[j] = mat[i][j]; // 是0 or 1
                else
                {
                    if (mat[i][j] == 0)
                        height[j] = 0;
                    else
                        height[j] = height[j] + 1; // 繼續數有多少個1
                }
            }

            // sum[j] -> 以j為右邊界有多少個矩形
            vector<int> sum(n + 5, 0);
            // 為了快速找到第一個在j左邊且height[i] < height[j]的i
            stack<int> monoSK;

            // 枚舉j作為目前矩形的最大高度
            for (int j = 0; j < n; ++j)
            {
                while (!monoSK.empty() && height[monoSK.top()] >= height[j])
                    monoSK.pop();
                
                if (!monoSK.empty())
                {
                    // 有一個leftIndex限制了高度
                    // 此時leftIndex + 1 ~ j之間的高度皆>=height[j]
                    // 同時還能跟比較短的邊做出比較長的矩形
                    // 能夠多出sum[leftIndex]個長矩形
                    int leftIndex = monoSK.top();
                    sum[j] = sum[leftIndex] + (j - leftIndex) * height[j];
                }
                else 
                {
                    // monoSk是空的 -> 在j之前所有的邊都比height[j]高
                    // 所以能夠做出(j + 1) * height[j]個矩形
                    sum[j] = (j + 1) * height[j];
                }
                
                res += sum[j];
                monoSK.push(j);
            }
        }

        return res;
    }
};


int main()
{
    vector<vector<int>> matrix = {{1,0,1},{1,1,0},{1,1,0}};
    Solution S;
    S.numSubmat(matrix);
}