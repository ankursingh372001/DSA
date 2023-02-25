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

int Countpair(int arr[], int n, int target) {
    
    int count = 0;
    
    int l = findMinIdx(arr, n);
    int r = (l - 1 + n) % n;
    
    while(l != r) {
        
        int sum = arr[l] + arr[r];
        
        if(sum < target) l = (l + 1) % n;
        else if(sum == target) count++, l = (l + 1) % n;
        else r = (r - 1 + n) % n;
    }
    
    if(count == 0) return -1;
        
    return count;
}

// https://practice.geeksforgeeks.org/problems/pair-with-given-sum-in-a-sorted-array4940/1