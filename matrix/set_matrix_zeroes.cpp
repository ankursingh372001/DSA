#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<int> matrix[], int m, int n) {
    
    bool x, y = false;

    for(int j = 0; j < n; ++j) if(matrix[0][j] == 0) x = true;
    for(int i = 0; i < m; ++i) if(matrix[i][0] == 0) y = true;
    
    for(int i = 1; i < m; ++i)
        for(int j = 1; j < n; ++j)
            if(matrix[i][j] == 0) {
                matrix[i][0] = matrix[0][j] = 0;
    
    for(int i = 1; i < m; ++i)
        for(int j = 1; j < n; ++j)
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
    
    if(x) for(int j = 0; j < n; ++j) matrix[0][j] = 0;
    if(y) for(int i = 0; i < m; ++i) matrix[i][0] = 0;
}

// https://leetcode.com/problems/set-matrix-zeroes/