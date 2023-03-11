#include<bits/stdc++.h>
using namespace std;

int dp[501][2001];

int f(vector<int>&nums, int k, int idx, int space) {
    
    if(idx == nums.size())
        return 0;
    
    if(dp[idx][space] != -1)
        return dp[idx][space];
        
    if(space < 1 + nums[idx])
        return dp[idx][space] = space * space + f(nums, k, idx + 1, k - nums[idx]);
        
    int take = f(nums, k, idx + 1, space - 1 - nums[idx]);
    int notTake = space * space + f(nums, k , idx + 1, k - nums[idx]);
    
    return dp[idx][space] = min(take, notTake);
}

int solveWordWrap(vector<int>nums, int k) {
    
    memset(dp, -1, sizeof(dp));
    
    return f(nums, k, 1, k - nums[0]);    
}

// https://practice.geeksforgeeks.org/problems/word-wrap1646/1