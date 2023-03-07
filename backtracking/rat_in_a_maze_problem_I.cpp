#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<string> ans;
    string curr;
    
    void f(vector<vector<int>>& grid, int r, int c, int n) {
        
        if(r == n - 1 && c == n - 1) {
            
            ans.push_back(curr);
            return;
        }
        
        grid[r][c] = 0;
        
        int dr[] = {-1, 0, 0, 1};
        int dc[] = {0, -1, 1, 0};
        int dir[] = {'U', 'L', 'R', 'D'};
        
        for(int i = 0; i < 4; ++i) {
            
            int R = r + dr[i];
            int C = c + dc[i];
            
            if(R >= 0 && R < n && C >= 0 && C < n && grid[R][C] == 1) {
                
                curr.push_back(dir[i]);
                
                f(grid, R, C, n);
                
                curr.pop_back();
            }
        }
        
        grid[r][c] = 1;
    }
    
    vector<string> findPath(vector<vector<int>>& grid, int n) {
        
        curr = "";
        
        if(grid[0][0] == 1)
            f(grid, 0, 0, n);
        
        return ans;
    }
};

// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1