#include<bits/stdc++.h>
using namespace std;

long long int dp[10001];

int f(int arr[], int n) {
    
    if(n == 0) return 0;    
    if(n == 1) return arr[0];
    
    if(dp[n] != -1) return dp[n];
        
    return dp[n] = max(arr[n - 1] + f(arr, n - 2), f(arr, n - 1));
}

int FindMaxSum(int arr[], int n) {
    
    memset(dp, -1, sizeof(dp));
    
    return f(arr, n);
}

// https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
