#include<bits/stdc++.h>
using namespace std;

int dp[2000][2000];
    
int f(string& s, string& p, int n, int m) {
        
    if (m == 0)
        return (n == 0);
        
    if (dp[n][m] != -1)
        return dp[n][m];
        
    if (n == 0)
        return dp[n][m] = (p[m - 1] == '*' ?  f(s, p, n, m - 1) : 0);
        
    if (p[m - 1] == s[n - 1])
        return dp[n][m] = f(s, p, n - 1, m - 1);

    if(p[m - 1] == '?')
        return dp[n][m] = f(s, p, n - 1, m - 1);

    if (p[m - 1] == '*')
        return dp[n][m] = f(s, p, n - 1, m) || f(s, p, n, m - 1);
        
    return dp[n][m] = 0;
}
    
bool isMatch(string& s, string& p) {
        
    memset(dp, -1, sizeof(dp));
        
    return f(s, p, s.length(), p.length());
}

// https://leetcode.com/problems/wildcard-matching/