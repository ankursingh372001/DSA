#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(int arr[], int n, int target) {
        
    vector<vector<int>> res;
        
    sort(arr, arr + n);
        
    int i = 0;
    while (i < n) {

        int j = i + 1;
        int k = n - 1;

        while (j < k) {

            int sum = arr[i] + arr[j] + arr[k];
                
            if (sum < target) {
                    
                j++;
                while (j < k && arr[j - 1] == arr[j]) j++;
            }
            else if (sum == target) {
                    
                res.push_back({arr[i], arr[j], arr[k]});
                    
                j++;
                while (j < k && arr[j - 1] == arr[j]) j++;
                    
                k--;
                while (j < k && arr[k] == arr[k + 1]) k--;
            }
            else {
                    
                k--;
                while (j < k && arr[k] == arr[k + 1]) k--;
            }
        }           
            
        i++;
        while (i < n && arr[i - 1] == arr[i]) i++;
    }
        
    return res;
}

// https://leetcode.com/problems/3sum/
