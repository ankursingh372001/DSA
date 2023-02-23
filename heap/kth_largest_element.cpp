#include<bits/stdc++.h>
using namespace std;

int findKthLargest(int arr[], int n, int k) {

    priority_queue<int, vector<int>, greater<int>> pq;
        
    for (int i = 0; i < k; ++i)
        pq.push(arr[i]);

    for (int i = k; i < n; ++i) {

        pq.push(arr[i]);
        pq.pop();
    }
 
    return pq.top();
}

// https://leetcode.com/problems/kth-largest-element-in-an-array/