#include<bits/stdc++.h>
using namespace std;

void countSort(int arr[], int n) {

    int k = *max_element(arr, arr + n);

    int count[k + 1] = {0};

    for (int i = 0; i < k; ++i) count[arr[i]]++;
    for (int i = 1; i < k; ++i) count[i] += count[i - 1];

    int output[n];
    for (int i = n - 1; i >= 0; --i) {

        count[arr[i]]--;
        output[count[arr[i]]] = arr[i];
    }

    arr = output;
}