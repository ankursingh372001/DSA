#include<bits/stdc++.h>
using namespace std;

void f(int n, int r, int t, vector<int>& curr, vector<vector<int>>& ans) {
    
    if(curr.size() == r) {
        
        ans.push_back(curr);
        return;
    }
    
    for(int i = t; i <= n; ++i) {
        
        curr.push_back(i);
        
        f(n, r, i + 1, curr, ans);
        
        curr.pop_back();
    }
}

vector<vector<int>> combine(int n, int r) {
    
    vector<vector<int>> ans;
    vector<int> curr;
    
    f(n, r, 1, curr, ans);
    
    return ans;
}

// https://leetcode.com/problems/combinations/