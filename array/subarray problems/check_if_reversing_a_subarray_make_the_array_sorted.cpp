#include<bits/stdc++.h>
using namespace std;

bool sortArr(int arr[], int n) {
    
    int i = 1;
    while(i < n && arr[i - 1] <= arr[i]) i++;
    
    int j = i;
    while(j < n && arr[j - 1] >= arr[j]) j++;
    
    reverse(arr + i - 1, arr + j);
    
    while(i < n && arr[i-1] <= arr[i]) i++;
    
    return i == n;
}

// https://www.codingninjas.com/codestudio/problems/sort-array_2653275