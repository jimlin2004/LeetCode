#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int maxLen = 0; // 區間內最長的連續相同字元長度
    char prefixChar = '\0'; // 最左邊的字元
    int prefixLen = 0; // 區間的前綴連續相同字元長度
    char suffixChar = '\0'; // 最右邊的字元
    int suffixLen = 0; // 區間的後綴連續相同字元長度
};

class SegmentTree
{
private:
    vector<Node> st;
    int n;
    string_view target_s;

    Node pull(const Node& Lnode, const Node& Rnode, int Llen, int Rlen)
    {
        Node res;
        res.prefixChar = Lnode.prefixChar;
        res.suffixChar = Rnode.suffixChar;
        res.maxLen = max(Lnode.maxLen, Rnode.maxLen);

        res.prefixLen = Lnode.prefixLen;
        res.suffixLen = Rnode.suffixLen;

        // 左右可以跨區合併
        if (Lnode.suffixChar == Rnode.prefixChar)
        {
            res.maxLen = max(res.maxLen, Lnode.suffixLen + Rnode.prefixLen);
            // 如果左邊的所有字元都一樣，此時前綴長度會跨區
            if (Lnode.prefixLen == Llen)
                res.prefixLen = Lnode.prefixLen + Rnode.prefixLen;
            // 如果右邊的所有字元都一樣，此時後綴長度會跨區
            if (Rnode.suffixLen == Rlen)
                res.suffixLen = Lnode.suffixLen + Rnode.suffixLen;
        }

        return res;
    }

    void build(int i, int l, int r)
    {
        if (l == r)
        {
            // 一個字的時候，長度自然是1
            st[i] = {1, target_s[l], 1, target_s[l], 1};
            return;
        }

        int mid = (l + r) >> 1;
        build(i * 2, l, mid);
        build(i * 2 + 1, mid + 1, r);
        st[i] = pull(st[i * 2], st[i * 2 + 1], mid - l + 1, r - mid);
    }

    void update(int i, int l, int r, int pos, char newC)
    {
        if (l == r)
        {
            st[i] = {1, newC, 1, newC, 1};
            return;
        }

        int mid = (l + r) >> 1;
        if (pos <= mid)
            update(i * 2, l, mid, pos, newC);
        else
            update(i * 2 + 1, mid + 1, r, pos, newC);
        st[i] = pull(st[i * 2], st[i * 2 + 1], mid - l + 1, r - mid);
    }
public:
    SegmentTree(const string_view str)
    {
        target_s = str;
        n = str.size();
        st.resize(4 * n);

        build(1, 0, n - 1);
    }

    void update(int pos, char newC)
    {
        update(1, 0, n - 1, pos, newC);
    }

    // root就是全域最長長度
    int getMaxLen()
    {
        return st[1].maxLen;
    }
};


class Solution
{
public:
    // 區間維護與合併 -> 線段樹，所以就只是要維護區間訊息與合併可能的線段樹靶題
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices)
    {
        int q = queryCharacters.size();
        
        vector<int> res(q, 0);
        SegmentTree segmentTree(s);

        for (int i = 0; i < q; ++i)
        {
            segmentTree.update(queryIndices[i], queryCharacters[i]);
            res[i] = segmentTree.getMaxLen();
        }

        return res;
    }
};