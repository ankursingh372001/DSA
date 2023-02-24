#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<int>& freqs, vector<int>& freqp) {
    
    for(int i = 0; i < 26; ++i)
        if(freqs[i] < freqp[i])
            return false;
            
    return true;
}

string smallestWindow (string s, string p) {

    string res = s + " ";
    
    vector<int> freqs(26, 0);
    vector<int> freqp(26, 0);
    
    for(char ch: p) freqp[ch - 'a']++;
    
    int l = 0;
    
    for(int r = 0; r < s.length(); ++r) {
    
        freqs[s[r] - 'a']++;
        
        while(isValid(freqs, freqp)) {
            
            if(res.length() > r - l + 1) 
                res = s.substr(l, r - l + 1);
                
            freqs[s[l] - 'a']--;
            l++;
        }
    }
    
    if(res.length() == s.length() + 1)  
        return "-1";
        
    return res;
}

// https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1