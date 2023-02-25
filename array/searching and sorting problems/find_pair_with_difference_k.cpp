#include<bits/stdc++.h>
using namespace std;

bool findPair(int arr[], int n, int diff){
    
    sort(arr, arr + n);
    
    for(int i = 0; i < n; ++i)
        if(binary_search(arr + i + 1, arr + n, arr[i] + diff))
            return true;
            
    return false;
}

// https://practice.geeksforgeeks.org/problems/find-pair-given-difference1559/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article