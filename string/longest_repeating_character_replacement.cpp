#include<bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {
        
    int ans = 0;
    int l = 0;
    vector<int> freq(26, 0);

    for(int r = 0; r < s.length(); ++r) {

        freq[s[r] - 'A']++;

        while(accumulate(freq.begin(), freq.end(), 0) - *max_element(freq.begin(), freq.end()) > k) {

            freq[s[l] - 'A']--;
            l++;
        }

        ans = max(ans, r - l + 1);
    }

    return ans;
}

// https://leetcode.com/problems/longest-repeating-character-replacement/description/