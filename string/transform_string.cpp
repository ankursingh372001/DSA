#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    
    bool isAnagram(string s, string t) {

        if(s.length() != t.length()) return -1;
            
        unordered_map<char, int> freq;
        
        for(auto x: s) freq[x]++;
        for(auto x: t) freq[x]--;
            
        for(auto x: freq) if(x.second) return false;

        return true;
    }

    int transform (string s, string t) {

        if(!isAnagram(s, t))
            return -1;

        int i = s.length() - 1;
        int j = t.length() - 1;
        int count = 0;

        while(i >= 0 && j >= 0) {

            if(s[i] == s[j]) {

                i--;
                j--;
            }
            else {

                count++;
                i--;
            }
        }
        
        return count;
    }
};

// https://practice.geeksforgeeks.org/problems/transform-string5648/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article
