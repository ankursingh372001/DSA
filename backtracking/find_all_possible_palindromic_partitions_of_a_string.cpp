#include<bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/find-all-possible-palindromic-partitions-of-a-string/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class Solution {
public:

    vector<vector<string>> ans;
    vector<string> curr;
    
    void f(string& s, int idx) {
        
        if(idx == s.length()) {
            
            ans.push_back(curr);
            return;
        }
        
        for(int i = idx; i < s.length(); ++i) {
            
            int l = idx;
            int r = i;
            
            bool flag = true;
            
            while(l < r) {
                
                if(s[l] != s[r]) {
                    
                    flag = false;
                    break;
                }
                
                l++;
                r--;
            }
            
            if(flag) {
                
                curr.push_back(s.substr(idx, i - idx + 1));
                
                f(s, i + 1);
                
                curr.pop_back();
            }
        }
    }
    
    vector<vector<string>> allPalindromicPerms(string s) {
        
        f(s, 0);
        
        return ans;
    }
};