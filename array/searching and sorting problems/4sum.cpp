#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(int nums[], int n, int target) {
    
    sort(nums, nums + n);
    
    vector<vector<int>> ans;
    
    int i = 0;
    while(i < n) {
        
        int j = i + 1;
        while(j < n) {
            
            int k = j + 1;
            int l = n - 1;
            
            while(k < l) {
                
                long long sum = 0ll + nums[i] + nums[j] + nums[k] + nums[l];
                
                if(sum < target) {
                    
                    k++;
                    while(k < n && nums[k - 1] == nums[k]) k++;
                } 
                else if(sum == target) {
                    
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    
                    k++; 
                    while(k < n && nums[k - 1] == nums[k]) k++;
                    
                    l--;
                    while(l > k && nums[l] == nums[l + 1]) l--;
                } 
                else {
                    
                    l--;
                    while(l > k && nums[l] == nums[l + 1]) l--;
                }
            }
            
            j++;
            while(j < n && nums[j - 1] == nums[j]) j++;
        }
        
        i++;
        while(i < n && nums[i - 1] == nums[i]) i++;
    }
    
    return ans;   
}