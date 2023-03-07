#include<bits/stdc++.h>
using namespace std;

long long findSubarray(long long arr[], int n) {
        
    map<long long,int> mp;
    
    mp[0]++;
    
    long long sum = 0;
    long long ans = 0;
    
    for(int i = 0; i < n; ++i) {
        
        sum += arr[i];
        
        ans += mp[sum];
        
        mp[sum]++;
    }
    
    return ans;
}

// https://practice.geeksforgeeks.org/problems/zero-sum-subarrays1825/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article