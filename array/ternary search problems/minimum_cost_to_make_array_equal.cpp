#include<bits/stdc++.h>
using namespace std;

long long computeCost(int nums[], int cost[], int n, int t) {

    long long ans = 0;

    for(int i = 0; i < n; ++i)
        ans += abs(nums[i] - t) * 1ll * cost[i];

    return ans;
}

long long minCost(int nums[], int cost[], int n) {
    
    long long ans = LLONG_MAX;

    int l = *min_element(nums, nums + n);
    int h = *max_element(nums, nums + n);

    while(l <= h) {

        int m1 = l + (h - l) / 3;
        int m2 = h - (h - l) / 3;

        long long cost1 = computeCost(nums, cost, n, m1);
        long long cost2 = computeCost(nums, cost, n, m2);

        if(cost1 < cost2) {
            ans = min(ans, cost1);
            h = m2 - 1;
        } else {
            ans = min(ans, cost2);
            l = m1 + 1;
        }
    }

    return ans;
}

// https://leetcode.com/problems/minimum-cost-to-make-array-equal/description/