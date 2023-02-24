#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;  

long long int dp[1000][1000];

long long int f(string&s, int l, int r) {
        
    if(l == r) return 1;
    if(l - r == 1) return 2 + (s[l] == s[r]);
        
    if(dp[l][r] != -1) return dp[l][r];
        
    if(s[l] == s[r]) return dp[l][r] = (1 + f(s, l + 1, r) + f(s, l, r - 1)) % MOD;
        
    return dp[l][r] = (MOD + f(s, l + 1, r) + f(s, l, r - 1) - f(s, l + 1, r - 1)) % MOD;
}

long long int  countPS(string str)
{
    memset(dp, -1, sizeof(dp));
    
    return f(str, 0, str.length() - 1);
}

// https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1