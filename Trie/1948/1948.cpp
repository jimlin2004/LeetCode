#include <bits/stdc++.h>
using namespace std;

/*
    算是資料結構題
    用類似trie的資結然後將子樹序列化後
    用hash看每個序列是否唯一即可
*/

struct Node
{
    string serial; // 子樹的序列化，因為題目只要子樹結構一樣
    unordered_map<string, Node*> children;
};

struct Trie
{
    Node* root;

    unordered_map<string, int> freqs; // 用來看每種序列化出現多少次

    Trie()
    {
        root = new Node();
    }

    void insert(vector<string>& path)
    {
        Node* curr = root;
        for (string& folder: path)
        {
            if (!curr->children.count(folder))
                curr->children[folder] = new Node();
            curr = curr->children[folder];
        }
    }

    // 用後序走訪序列化Trie
    void serialized(Node* curr)
    {
        // leaf node
        if (curr->children.empty())
        {
            curr->serial = "";
            return;
        }

        vector<string> childrenSerial;

        for (auto& [folder, child]: curr->children)
        {
            serialized(child);
            string childSerial = folder + "(" + child->serial + ")";
            childrenSerial.push_back(childSerial);
        }

        // 為了保持serial中children的拜訪順序，用字典序sort
        sort(childrenSerial.begin(), childrenSerial.end());

        curr->serial = "";
        for (string& childSerial: childrenSerial)
            curr->serial += childSerial;

        ++freqs[curr->serial];
    }

    // deleteDuplicateFolder
    void dfs(Node* curr, vector<string>& currPath, vector<vector<string>>& res)
    {
        if (freqs[curr->serial] > 1) // 有重複的
            return;

        if (!currPath.empty())
            res.push_back(currPath);

        for (auto& [folder, child]: curr->children)
        {
            currPath.push_back(folder);
            dfs(child, currPath, res);
            currPath.pop_back();
        }
    }
};


class Solution 
{
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) 
    {
        vector<string> currPath;
        vector<vector<string>> res;
        
        Trie trie;
        for (vector<string>& path: paths)
        {
            trie.insert(path);
        }

        trie.serialized(trie.root);

        trie.dfs(trie.root, currPath, res);

        return res;
    }
};