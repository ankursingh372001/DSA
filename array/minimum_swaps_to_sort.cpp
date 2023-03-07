#include<bits/stdc++.h>
using namespace std;

int minSwaps(vector<int>&nums) {
    
    vector<vector<int>> v;
    for(int i = 0; i < nums.size(); ++i)
        v.push_back({nums[i], i});
        
    sort(v.begin(), v.end());
    
    int swaps = 0;
    
    for(int i = 0; i < v.size(); ++i) {
        
        while(v[i][1] != i) {
            
            swap(v[i], v[v[i][1]]);
            swaps++;
        }
    }
    
    return swaps;
}

// https://practice.geeksforgeeks.org/problems/minimum-swaps/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article