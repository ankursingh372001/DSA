#include<bits/stdc++.h>
using namespace std;

bool isValid(unordered_map<int,int>& freqs, unordered_map<int,int>& freqp) {
    
    for(char x = 'a'; x <= 'z'; ++x) if(freqs[x] < freqp[x]) return false;
    for(char x = 'A'; x <= 'Z'; ++x) if(freqs[x] < freqp[x]) return false;

    return true;
}

string smallestWindow (string s, string p) {

    unordered_map<int,int> freqs;
    unordered_map<int,int> freqp;
    
    int l = 0;
    int r = s.length() + 1;

    for(char x: p) freqp[x]++;
    
    int i = 0;
    for(int j = 0; j < s.length(); ++j) {
    
        freqs[s[j]]++;

        while(isValid(freqs, freqp)) {
            
            if(r - l + 1 > j - i + 1) {

                l = i;
                r = j;
            }
                
            freqs[s[i]]--;
            i++;
        }
    }
    
    if(r == s.length() + 1) return "";
        
    return s.substr(l, r - l + 1);
}

// https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1
// https://leetcode.com/problems/minimum-window-substring/description/