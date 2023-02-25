#include<bits/stdc++.h>
using namespace std;

vector<int> spiralTraversal (vector<int> grid[], int m, int n) {

    vector<int> ans(m * n);

    int ri = 0;
    int ci = 0;
    int rf = m - 1;
    int cf = n - 1;
        
    while (ri < rf && ci < cf) {

        for (int j = ci; j < cf; ++j) ans.push_back(grid[ri][j]);
        for (int i = ri; i < rf; ++i) ans.push_back(grid[i][cf]);
        for (int j = cf; j > ci; --j) ans.push_back(grid[rf][j]);
        for (int i = rf; i > ri; --i) ans.push_back(grid[i][ci]);
            
        ri++;
        rf--;
        ci++;            
        cf--;
    }
        
    if (ri == rf) for (int j = ci; j <= cf; ++j) ans.push_back(grid[ri][j]);
    else if (ci == cf) for (int i = ri; i <= rf; ++i) ans.push_back(grid[i][ci]);

    return ans;
}

// https://leetcode.com/problems/spiral-matrix/