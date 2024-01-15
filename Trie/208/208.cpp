#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node() {}
    Node(char c) {this->val = c; is_word = false;}
    char val;
    unordered_map<char, Node*> child;
    bool is_word;
};

class Trie 
{
public:
    Trie() 
    {
        root = new Node();
    }
    
    void insert(string word) 
    {
        Node* current = this->root;
        for (char c: word)
        {
            if (current->child.find(c) == current->child.end())
                current->child[c] = new Node(c);
            current = current->child[c];
        }
        current->is_word = true;
        return;
    }
    
    bool search(string word) 
    {
        Node* current = this->root;
        for (char c: word)
        {
            if (current->child.find(c) == current->child.end())
                return false;
            current = current->child[c];
        }
        return current->is_word;
    }
    
    bool startsWith(string prefix) 
    {
        Node* current = this->root;
        for (char c: prefix)
        {
            if (current->child.find(c) == current->child.end())
                return false;
            current = current->child[c];
        }
        return true;
    }

private:
    Node* root;
};

int main()
{
    Trie* trie = new Trie();
    trie->insert("apple");
    return 0;
}