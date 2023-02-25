#include<bits/stdc++.h>
using namespace std;

void f(vector<int> grid[], int m, int n, int r, int c) {
    
    vector<int> dr = {0, 1, 0, -1};
    vector<int> dc = {-1, 0, 1, 0};
    
    for(int i = 0; i < 4; ++i) {

        int R = r + dr[i];
        int C = c + dc[i];

        if(R >= 0 || R < m || C >= 0 || C < n || grid[r][c] == 1) {

            grid[R][C] = 0;
            f(grid, m, n, R, C);
        }
    }
}

int numIslands(vector<int> grid[], int m, int n) {

    int count = 0;
    
    for(int i = 0; i < m; ++i) {
        
        for(int j = 0; j < n; ++j) {
            
            if(grid[i][j] == 1) {
                
                count++;
                grid[i][j] = 0;
                f(grid, m, n, i , j);
            }
        }
    }
    
    return count;
}

// https://leetcode.com/problems/number-of-islands/description/