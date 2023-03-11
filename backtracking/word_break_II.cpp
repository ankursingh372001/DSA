#include<bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/word-break-part-23249/1

class TrieNode{
public:
    bool flag;
    TrieNode* child[26];
    
    TrieNode() {
        
        flag = false;
        for(int i = 0; i < 26; ++i)
            child[i] = NULL;
    }
};

TrieNode* insert(TrieNode* root, string s) {

    TrieNode* curr = root;
    
    for(int i = 0; i < s.length(); ++i) {
        
        if(curr->child[s[i] - 'a'] == NULL)
            curr->child[s[i] - 'a'] = new TrieNode();
            
        curr = curr->child[s[i] - 'a'];
    }
    
    curr->flag = true;
    
    return root;
}

class Solution {
public:
    vector<string> ans;
    
    void f(string& s, int idx, TrieNode* root, string curr) {
        
        if(idx == s.length()) {
            
            ans.push_back(curr);
            return;
        }
        
        TrieNode* temp = root;
        
        for(int i = idx; i < s.length(); ++i) {
            
            temp = temp->child[s[i] - 'a'];
            
            if(temp == NULL)
                return;
            
            if(temp->flag)
                f(s, i + 1, root, curr + (curr == "" ? "" : " ") + s.substr(idx, i - idx + 1));
        }
    }
    
    vector<string> wordBreak(int n, vector<string>& dict, string s) {
        
        TrieNode* root = new TrieNode();
        
        for(int i = 0; i < n; ++i)
            root = insert(root, dict[i]);
            
        f(s, 0, root, "");
        
        return ans;
    }
};