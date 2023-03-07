#include<bits/stdc++.h>
using namespace std;

// TC : O(n)
// SC : O(1)
void findDuplicates(int arr[], int n) {

    for(int i = 0; i < n; ++i)
        arr[arr[i] % n] += n;
    
    for(int i = 1; i < n; ++i)
        if(arr[i] > 2 * n)
            cout << arr[i] << " ";
    
    if(arr[0] > 2 * n)
        cout << n << " ";
}

// https://leetcode.com/problems/find-all-duplicates-in-an-array/description/