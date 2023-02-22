#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

int maxProfit(vector<int>& prices) {

    int n = prices.size();

    int ans = 0;
    int mini = prices[0];
    
    for (int i = 1; i < n; ++i) {

        if (prices[i] < mini) {

            mini = prices[i];
        }
        else {

            int profit = prices[i] - mini;

            ans = max(ans, profit);
        }
    }

    return ans;
}