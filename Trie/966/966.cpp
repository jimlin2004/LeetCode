#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    static const char minc = 'A';
    static const char maxc = 'z' + 5;

    bool isWord;
    int idx = 0x3f3f3f3f; // 在原本wordlist的第幾個
    TrieNode* child[maxc];
};

struct QueryInfo
{
    string found = "";
    int idx = 0x3f3f3f3f;
    int weight = 4; // 全對 1，只錯大小寫 2，有錯vowel 3，沒匹配 4
};

class Trie
{
private:
    TrieNode* root;
    static const vector<char> vowels;

    inline bool isVowel(char c)
    {
        for (const char vowel: vowels)
        {
            if (c == vowel)
                return true;
        }
        return false;
    } 

    bool queryDFS(TrieNode* curr, string str, QueryInfo& queryInfo, bool isCapError, bool isVowelError, const string& target, int targetIdx)
    {
        if (targetIdx == target.size()) // 到頭了
        {
            if (!curr->isWord)
                return false;

            if (!isCapError) // exactly match
            {
                queryInfo.found = str;
                queryInfo.idx = curr->idx;
                queryInfo.weight = 1;
            }
            else if (!isVowelError) // 只有大小寫錯誤
            {
                if (queryInfo.weight > 2 || (queryInfo.weight == 2 && queryInfo.idx > curr->idx))
                {
                    queryInfo.found = str;
                    queryInfo.idx = curr->idx;
                    queryInfo.weight = 2;
                }
            }
            else // 有錯vowel
            {
                if (queryInfo.weight > 3 || (queryInfo.weight == 3 && queryInfo.idx > curr->idx))
                {
                    queryInfo.found = str;
                    queryInfo.idx = curr->idx;
                    queryInfo.weight = 3;
                }
            }
            return true;
        }

        char targetC = target[targetIdx];
        char anotherCapTargetC = '\0';
        if (isupper(target[targetIdx]))
            anotherCapTargetC = tolower(target[targetIdx]);
        else
            anotherCapTargetC = toupper(target[targetIdx]);

        bool found = false;

        // 直接有這個char
        if (curr->child[targetC - TrieNode::minc] != nullptr)
            found = queryDFS(curr->child[targetC - TrieNode::minc], str + targetC, queryInfo, isCapError, isVowelError, target, targetIdx + 1);
        // exactly match
        if (found && queryInfo.weight == 1)
            return true;
        
        // 有這個不管大小寫的
        if (curr->child[anotherCapTargetC - TrieNode::minc] != nullptr)
            found |= queryDFS(curr->child[anotherCapTargetC - TrieNode::minc], str + anotherCapTargetC, queryInfo, true, isVowelError, target, targetIdx + 1);
        // 只換大小寫就能找到了
        if (found && queryInfo.weight == 2)
            return true;

        // 嘗試換vowel
        if (isVowel(target[targetIdx]))
        {
            for (const char vowel: vowels)
            {
                if (curr->child[vowel - TrieNode::minc] != nullptr)
                    found |= queryDFS(curr->child[vowel - TrieNode::minc], str + vowel, queryInfo, true, true, target, targetIdx + 1);
            }
        }

        return found;
    }

public:
    Trie()
    {
        root = new TrieNode();
        root->isWord = false;
        memset(root->child, 0, sizeof(root->child));
    }

    TrieNode* addNode()
    {
        TrieNode* newNode = new TrieNode();
        newNode->isWord = false;
        memset(newNode->child, 0, sizeof(newNode->child));
        return newNode;
    }

    void insert(const string& word, int idx)
    {
        int n = word.size();

        TrieNode* curr = root;

        for (int i = 0; i < n; ++i)
        {
            char c = word[i] - TrieNode::minc;
            if (!curr->child[c])
                curr->child[c] = addNode();
            curr = curr->child[c];
        }

        curr->isWord = true;
        curr->idx = min(curr->idx, idx); // 用min避免有重複word
    }

    string query(const string& target)
    {
        QueryInfo queryInfo;
        queryDFS(root, "", queryInfo, false, false, target, 0);

        return queryInfo.found;
    }
};

const vector<char> Trie::vowels = {
        'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'
};

class Solution
{
public:
    // 用trie爆破
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries)
    {
        Trie trie;

        int n = wordlist.size();
        for (int i = 0; i < n; ++i)
            trie.insert(wordlist[i], i);

        vector<string> res;
        for (auto& queryStr: queries)
            res.emplace_back(trie.query(queryStr));

        return res;
    }
};


int main()
{
    vector<string> wordlist = {"zeo","Zuo"};
    vector<string> queries = {"zuo"};
    // vector<string> queries = {"keti","keto"};
    Solution S;
    S.spellchecker(wordlist, queries);

    return 0;
}