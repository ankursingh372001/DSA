#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    
    vector<vector<int>> ans;
    vector<int> curr;
    
    bool isValid(vector<vector<int>>& board, int n, int r, int c) {
        
        for(int R = r - 1; R >= 0; --R) 
            if(board[R][c] == 1)
                return false;
            
        for(int R = r - 1, C = c - 1; R >= 0 && C >= 0; --R, --C) 
            if(board[R][C] == 1)
                return false;
                
        for(int R = r - 1, C = c + 1; R >= 0 && C < n; --R, ++C)
            if(board[R][C] == 1)
                return false;
                
        return true;
    }
    
    void f(vector<vector<int>>& board, int n, int r) {
        
        if(r == n) {
            
            ans.push_back(curr);
            return;
        }
        
        for(int c = 0; c < n; ++c) {
            
            if(isValid(board, n, r, c)) {
                
                board[r][c] = 1;
                
                curr.push_back(c + 1);
                
                f(board, n, r + 1);
                
                curr.pop_back();
                
                board[r][c] = 0;
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        
        vector<vector<int>> board(n, vector<int>(n, 0));
        
        f(board, n, 0);
        
        return ans;
    }
};

// https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article