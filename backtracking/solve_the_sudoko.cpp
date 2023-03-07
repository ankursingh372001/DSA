#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<vector<int>>> ans;
    
    bool isValid(vector<vector<int>>& board, int r, int c, int k) {
        
        for(int R = 0; R < 9; ++R)
            if(board[R][c] == k)
                return false;
                
        for(int C = 0; C < 9; ++C)
            if(board[r][C] == k)
                return false;
        
        for(int R = r / 3 * 3; R < r / 3 * 3 + 3; ++R)
            for(int C = c / 3 * 3; C < c / 3 * 3 + 3; ++C)
                if(board[R][C] == k)
                    return false;
                
        return true;
    }
    
    void f(vector<vector<int>>& board, int r, int c) {
        
        if(r == 9) {
            
            ans.push_back(board);
            return;
        }
            
        if(board[r][c] != 0) {
            
            f(board, r + (c + 1) / 9, (c + 1) % 9);
            return;
        }
        
        for(int i = 1; i <= 9; ++i) {
            
            if(isValid(board, r, c, i)) {
                
                board[r][c] = i;
                
                f(board, r + (c + 1) / 9, (c + 1) % 9); 
                
                board[r][c] = 0;
            }
        }
    }
    
    bool SolveSudoku(vector<vector<int>>& board) {
                
        f(board, 0, 0);
        
        if(ans.empty())
            return false;
            
        return true;
    }
};

// https://practice.geeksforgeeks.org/problems/solve-the-sudoku-1587115621/1