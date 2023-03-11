#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/word-search/

bool f(vector<vector<char>>& board, int r, int c, string& word, int idx) {
    
    if(idx == word.size() - 1)
        return true;
    
    char temp = board[r][c];
    
    board[r][c] = ' ';
    
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    
    for(int i = 0; i < 4; ++i) {
        
        int R = r + dr[i];
        int C = c + dc[i];
        
        if(R >= 0 && R < board.size() && C >= 0 && C < board[0].size() && board[R][C] == word[idx + 1])
            if(f(board, R, C, word, idx + 1))
                return true;
    }
                
    board[r][c] = temp;
    
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    
    for(int i = 0; i < board.size(); ++i)
        for(int j = 0; j < board[i].size(); ++j)
            if(board[i][j] == word[0])
                if(f(board, i, j, word, 0))
                    return true;
    
    return false;
}