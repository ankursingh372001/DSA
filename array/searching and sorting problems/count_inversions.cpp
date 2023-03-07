#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r, int& res) {
        
    int n1 = m - l + 1;
    int n2 = r - m;
        
    int arr1[n1];
    int arr2[n2];
        
    for (int i = 0; i < n1; ++i) arr1[i] = arr[l + i];
    for (int i = 0; i < n2; ++i) arr2[i] = arr[m + 1 + i];
        
    int i = 0;
    int j = 0;
    int k = l;
        
    int t = 0; // array 2 ke kitne bande jaa chuke hain

    while (i < n1 && j < n2) {
            
        if (arr1[i] <= arr2[j]) {

            arr[k++] = arr1[i++];
            res += t;
        }
        else {
            
            arr[k++] = arr2[j++];
            t++;
        }
    }
        
    while (i < n1) {

        arr[k++] = arr1[i++];
        res += t;
    }
            
    while (j < n2) {

        arr[k++] = arr2[j++];
    }
}
    
void mergeSort(int arr[], int l, int r, int& res) {
        
    if (l < r) {
            
        int m = l + (r - l) / 2;
            
        mergeSort(arr, l, m, res);
        mergeSort(arr, m+1, r, res);
            
        merge(arr, l, m, r, res);
    }
}
    
int inversionCount(int arr[], int n) {

    int res = 0;
        
    mergeSort(arr, 0, n-1, res);
        
    return res;
}

// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1