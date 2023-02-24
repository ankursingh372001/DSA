#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
    map<vector<int>, vector<string>> mp;
    
    for(int i = 0; i < strs.size(); ++i) {
        
        vector<int> freq(26, 0);
        
        for(char& ch: strs[i]) freq[ch - 'a']++;
        
        mp[freq].push_back(strs[i]);
    }
    
    vector<vector<string>> ans;

    for(auto t: mp)
        ans.push_back(t.second);
    
    return ans;
}

// https://leetcode.com/problems/group-anagrams/