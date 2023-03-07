#include<bits/stdc++.h>
using namespace std;

int longSubarrWthSumDivByK(int arr[], int n, int k) {
    
    unordered_map<int,int>mp;
    long long sum = 0;
    int ans = 0;

    mp[0] = -1;
    
    for(int i = 0; i < n; ++i) {
        
        sum = (sum % k + arr[i] % k + k) % k;
        
        if(mp.find(sum) != mp.end()) 
            ans = max(ans, i - mp[sum]);
        else 
            mp[sum] = i;
    }
    
    return ans;
}

// https://practice.geeksforgeeks.org/problems/longest-subarray-with-sum-divisible-by-k1259/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article