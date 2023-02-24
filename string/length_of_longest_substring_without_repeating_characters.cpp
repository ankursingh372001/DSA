#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {

    int ans = 0;
    int l = 0;
    unordered_map<char,int> lastIdx;

    for(int i = 0; i < s.length(); ++i) {

        if(lastIdx.find(s[i]) != lastIdx.end()) l = max(l, lastIdx[s[i]] + 1);

        ans = max(ans, i - l + 1);
        
        lastIdx[s[i]] = i;
    }

    return ans;
}

// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/