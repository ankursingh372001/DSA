#include<bits/stdc++.h>
using namespace std;

int findMinIdx(int arr[], int n) {
    
    int idx = 0;
    int l = 0;
    int r = n - 1;
    
    while(l <= r) {
        
        int m = l + (r - l) / 2;    
        
        if(arr[0] <= arr[m]) l = m + 1;
        else if(arr[m] < arr[idx]) idx = m, r = m - 1;
        else r = m - 1;
    }
    
    return idx;
}

int search(int arr[], int n, int key) {
    
    int idx = findMinIdx(arr, n);

    bool check1 = binary_search(arr, arr + idx, key);
    bool check2 = binary_search(arr + idx, arr + n, key);

    return check1 || check2;
}

// https://leetcode.com/problems/search-in-rotated-sorted-array/description/