#include<bits/stdc++.h>
using namespace std;

int findKthLargest(int arr[], int n, int k) {

    priority_queue<int> pq;
        
    for (int i = 0; i < k; ++i)
        pq.push(arr[i]);

    for (int i = k; i < n; ++i) {

        pq.push(arr[i]);
        pq.pop();
    }
 
    return pq.top();
}

// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1