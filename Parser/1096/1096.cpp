#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    /*
        這題基本上就是一個context-free grammar的實作
        既然是CFG，那自然想到push down machine
        但其實可以用遞迴的去解即可
    */

    // 處理笛卡兒積
    vector<string> multiply(const vector<string>& A, const vector<string>& B)
    {
        vector<string> res;
        for (const string& a: A)
        {
            for (const string& b: B)
            {
                res.emplace_back(a + b);
            }
        }

        return res;
    }

    // 處理基本單元: 一個字元或是{Expr}
    vector<string> parseFactor(const string& s, int& idx)
    {
        if (s[idx] == '{')
        {
            ++idx; // 吃掉{
            vector<string> res = parseExpr(s, idx);
            ++idx; // 吃掉}
            return res;
        }
        else
        {
            // 連續小寫字母
            string word = "";
            while (idx < s.size() && isalpha(s[idx]))
            {
                word += s[idx++];
            }
            return {word};
        }
    }

    // 處理串接
    vector<string> parseTerm(const string& s, int& idx)
    {
        vector<string> curr = {""}; // 放入一個基本單位元
        // 只要不是逗號、不是又括號，就是接著一個factor
        while (idx < s.size() && s[idx] != ',' && s[idx] != '}')
        {
            vector<string> nextFactor = parseFactor(s, idx);
            curr = multiply(curr, nextFactor);
        }

        return curr;
    }

    // 處理聯集
    vector<string> parseExpr(const string& s, int& idx)
    {
        vector<string> res;
        while(true)
        {
            vector<string> term = parseTerm(s, idx);
            res.insert(res.end(), term.begin(), term.end());

            // 如果後面是逗號，吃掉逗號繼續處理下一個term
            if (idx < s.size() && s[idx] == ',')
                ++idx; // 吃掉,
            else
                break;
        }

        return res;
    }

    vector<string> braceExpansionII(string expression) 
    {
        int idx = 0; // 現在處理到哪個index
        vector<string> allWords = parseExpr(expression, idx);
        // 排序與去重
        sort(allWords.begin(), allWords.end());
        auto uniqueEnd = unique(allWords.begin(), allWords.end());
        vector<string> res(allWords.begin(), uniqueEnd);

        return res;
    }
};