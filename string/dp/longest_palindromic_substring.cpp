#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];

bool isPallindrome(string& s, int l, int r) {
    
    if(l >= r) return true;
    
    if(dp[l][r] != -1) return dp[l][r];
    
    if(s[l] != s[r]) return dp[l][r] = false;
    
    return dp[l][r] = isPallindrome(s, l + 1, r - 1);
}

string longestPalindrome(string s) {

    memset(dp, -1, sizeof(dp));
    
    string res = "";
    
    for(int i = 0; i < s.length(); ++i)
        for(int j = i; j < s.length(); ++j)
            if(isPallindrome(s, i, j))
                if(res.length() < j - i + 1)
                    res = s.substr(i, j - i + 1);
    
    return res;
}

// https://leetcode.com/problems/longest-palindromic-substring/
// https://leetcode.com/problems/palindromic-substrings/description/