#include<bits/stdc++.h>
using namespace std;

void transponse(vector<int> matrix[], int n) {

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            swap(matrix[i][j], matrix[j][i]);
}

void rotate(vector<int> matrix[], int n) {

    transponse(matrix, n);
        
    for (int i = 0; i < n; ++i)
        reverse(matrix[i].begin(), matrix[i].end());
}

// https://leetcode.com/problems/rotate-image/