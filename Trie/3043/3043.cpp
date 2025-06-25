#include <bits/stdc++.h>
using namespace std;

/*
    建Trie後dfs搜最長
*/

#define maxc 10
#define minc '0'

struct TrieNode
{
    TrieNode* child[maxc];

    TrieNode()
    {
        memset(child, 0, sizeof(child));
    }
};

struct Trie
{
    TrieNode* root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode* curr = root;
        for (char ch: word)
        {
            int c = ch - minc;
            if (!curr->child[c])
            {
                curr->child[c] = new TrieNode();
            }
            curr = curr->child[c];
        }
    }
};

class Solution 
{
public:

    int res = 0;

    void dfs(int cnt, TrieNode* curr1, TrieNode* curr2)
    {
        for (int c = 0; c < maxc; ++c)
        {
            if (curr1->child[c] && curr2->child[c])
            {
                dfs(cnt + 1, curr1->child[c], curr2->child[c]);
            }
        }

        res = max(res, cnt);
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) 
    {
        Trie trie1;
        Trie trie2;

        for (int val: arr1)
            trie1.insert(to_string(val));
        
        for (int val: arr2)
            trie2.insert(to_string(val));
        
        dfs(0, trie1.root, trie2.root);

        return res;
    }
};


int main()
{
    vector<int> arr1 = {1, 10, 100};
    vector<int> arr2 = {1000};
    Solution S;
    S.longestCommonPrefix(arr1, arr2);

    return 0;
}