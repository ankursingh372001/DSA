#include<bits/stdc++.h>
using namespace std;

void f(vector<vector<int>>& matrix, int m, int n, int r, int c) {
    
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    
    for(int i = 0; i < 4; ++i) {
        
        int R = r + dr[i];
        int C = c + dc[i];
        
        if(R >= 0 && R < m && C >= 0 && C < n && matrix[R][C] == 0) {

            matrix[R][C] = -1;
            f(matrix, m, n, R, C);
        }
    }
}

void solve(vector<vector<int>>& matrix, int m, int n) {
    
    for(int j = 0; j < n; ++j)  if(matrix[0][j] == 0)        matrix[0][j] = -1,      f(matrix, m, n, 0, j);
    for(int i = 0; i < m; ++i)  if(matrix[i][n - 1] == 0)    matrix[i][n - 1] = -1,  f(matrix, m, n, i, n - 1);
    for(int j = 0; j < n; ++j)  if(matrix[m - 1][j] == 0)    matrix[m - 1][j] = -1,  f(matrix, m, n, m - 1, j);
    for(int i = 0; i < m; ++i)  if(matrix[i][0] == 0)        matrix[i][0] = -1,      f(matrix, m, n, i, 0);
    
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            if(matrix[i][j] == -1 ) matrix[i][j] = 0;
            else if(matrix[i][j] == 0) matrix[i][j] = 1;
}

// https://leetcode.com/problems/surrounded-regions/