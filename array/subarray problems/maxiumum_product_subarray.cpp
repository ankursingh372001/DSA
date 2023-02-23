#include<bits/stdc++.h>
using namespace std;

int maxProduct(int arr[], int n) {

    int ans = arr[0];
    int minn = arr[0];
    int maxx = arr[0];

    for (int i = 1; i < n; ++i) {

        int temp = maxx;

        maxx = max({maxx * arr[i], minn * arr[i], arr[i]});

        minn = min({temp * arr[i], minn * arr[i], arr[i]});

        ans  = max(ans, maxx);
    }

    return ans;
}

// https://leetcode.com/problems/maximum-product-subarray/