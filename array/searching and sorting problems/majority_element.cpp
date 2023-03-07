#include<bits/stdc++.h>
using namespace std;

int majorityElement(int arr[], int n) {

    int ans = arr[0];
    int count = 1;
    
    for(int i = 1; i < n; ++i) {

        if(arr[i] == ans) count++;
        else count--;
        
        if(count == 0) {

            ans = arr[i];
            count = 1;
        }
    }
    
    return ans;
}

// https://leetcode.com/problems/majority-element/