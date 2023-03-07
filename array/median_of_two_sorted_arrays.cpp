#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(int arr1[], int m, int arr2[], int n) {

    if (m > n)
        return findMedianSortedArrays(arr2, n, arr1, m);

    int lo = 0;
    int hi = m;

    int t = (m + n + 1) / 2; // number of elements that I have to keep on left

    while (lo <= hi) {

        int cut1 = lo + (hi - lo) / 2; // select cut1 elements from arr1
        int cut2 = t - cut1; // select cut2 elements from arr2

        int l1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
        int r1 = (cut1 == m) ? INT_MAX : arr1[cut1];
        int r2 = (cut2 == n) ? INT_MAX : arr2[cut2];

        if (l1 <= r2 && l2 <= r1) {

            if ((m + n) & 1)
                return max(l1,l2);
            else
                return (max(l1,l2) + min(r1,r2)) / 2.0;
        }
        else if (l1 > r2) {

            hi = cut1 - 1;
        }
        else {

            lo = cut1 + 1;
        }
    }

    return 0.0;
}

// https://leetcode.com/problems/median-of-two-sorted-arrays/description/