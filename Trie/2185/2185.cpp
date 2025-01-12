#include <bits/stdc++.h>
using namespace std;

#define maxc 26
#define minc 'a'

struct TrieNode
{
    int cnt;
    TrieNode* child[maxc];
    TrieNode()
    {
        cnt = 0;
        memset(child, 0, sizeof(child));
    }
};

struct Trie
{
    TrieNode* root;
    Trie()
    {
        this->root = new TrieNode();
    }

    void insert(const string& word)
    {
        TrieNode* curr = this->root;
        for (char c: word)
        {
            char ch = c - minc;
            if (!curr->child[ch])
                curr->child[ch] = new TrieNode();
            curr = curr->child[ch];
            ++curr->cnt;
        }
    }

    int queryPrefix(const string& prefix)
    {
        TrieNode* curr = this->root;
        for (char c: prefix)
        {
            char ch = c - minc;
            if (!curr->child[ch])
                return 0;
            curr = curr->child[ch];
        }
        return curr->cnt;
    }
};

class Solution 
{
public:
    // 直接砸Trie
    int prefixCount(vector<string>& words, string pref) 
    {
        Trie trie;
        for (const string& word: words)
            trie.insert(word);
        return trie.queryPrefix(pref);
    }
};