#include<bits/stdc++.h>
using namespace std;

int dp[101][10001];
    
bool f(int arr[], int n, int target) {
    
    if(target == 0)
        return 1;
        
    if(n == 0)
        return 0;
        
    if(dp[n][target] != -1)
        return dp[n][target];
        
    if(arr[n - 1] > target)
        return dp[n][target] = f(arr, n - 1, target);
        
    return dp[n][target] = f(arr, n - 1, target) || f(arr, n - 1, target - arr[n - 1]);
}

int equalPartition(int arr[], int n) {

    memset(dp, -1, sizeof(dp));

    int sum = accumulate(arr, arr + n, 0);
    
    if(sum & 1)
        return 0;

    return f(arr, n, sum / 2);
}

// https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1