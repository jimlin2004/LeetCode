#include <bits/stdc++.h>
using namespace std;

/*
    直接使用Trie去爆破
    每個path都放進去
    然後dfs時遇到第一個done就直接結束dfs回傳path答案即可
*/

struct Node
{
    unordered_map<string, Node*> child;
    bool isDone;
    string foldName;

    Node(bool isDone, const string& foldName)
        : isDone(isDone), foldName(foldName)
    {
    };
};

struct Trie
{
    Node* root;

    Trie()
    {
        root = new Node(false, "");
    }

    void insert(const string& path)
    {
        stringstream ss(path);
        string token;
        vector<string> tokens;
        
        Node* curr = root;

        while (getline(ss, token, '/'))
        {
            // 第一個會切出""，所以跳過
            if (token == "")
                continue;
            if (curr->child.find(token) == curr->child.end())
            {
                curr->child.insert({token, new Node(false, token)});
            }
            curr = curr->child[token];
        }
        curr->isDone = true;
    }

    vector<string> getAllFoldWithoutSubfolder()
    {
        vector<string> res;
        for (auto& [foldName, nextNode]: root->child)
        {
            dfs(nextNode, "", res);
        }

        return res;
    }

    void dfs(Node* curr, string path, vector<string>& res)
    {
        path += "/" + curr->foldName;

        if (curr->isDone)
        {
            res.push_back(path);
            return;
        }

        for (auto& [foldName, nextNode]: curr->child)
        {
            dfs(nextNode, path, res);
        }
    }
};

class Solution 
{
public:
    vector<string> removeSubfolders(vector<string>& folder)
    {
        Trie trie;
        for (string& path: folder)
        {
            trie.insert(path);
        }

        return trie.getAllFoldWithoutSubfolder();
    }
};


int main()
{
    Solution S;
    vector<string> folders = {"/a","/a/b","/c/d","/c/d/e","/c/f"};
    S.removeSubfolders(folders);

    return 0;
}