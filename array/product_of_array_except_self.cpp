#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/product-of-array-except-self/

vector<int> productExceptSelf(vector<int> nums) {

    int n = nums.size();
    
    int product = 1;
    int zero_count = 0;

    for (int i = 0; i < n; ++i) {

        if (nums[i] == 0)
            zero_count++;
        else
            product *= nums[i];
    }

    vector<int> ans(n,0);

    if (zero_count == 0)
        for (int i = 0; i < n; ++i)
            ans[i] = product / nums[i];

    if (zero_count == 1)
        for (int i = 0; i < n; ++i)
            if (nums[i] == 0)
                ans[i] = product;

    return ans;
}
