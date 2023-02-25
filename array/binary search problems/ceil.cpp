#include<bits/stdc++.h>
using namespace std;

int ceil(int arr[], int n, int key) {

    int ans = -1;

    int l = 0;
    int r = n - 1;

    while (l <= r) {

        int m = l + (r - l) / 2;
        
        if (arr[m] < key) l = m + 1;
        else ans = arr[m], r = m - 1;
    }

    return ans;
}
