#include<bits/stdc++.h>
using namespace std;

int maximumSubarraySum(int arr[], int n) {

    int curSum = arr[0];
    int maxSum = INT_MIN;
        
    for(int i = 1; i < n; ++i) {
    
        if (curSum < 0) curSum = arr[i];
        else curSum += arr[i];
        
        if(maxSum < curSum) maxSum = curSum;
    }
                
    return maxSum;
}

// https://leetcode.com/problems/maximum-subarray/