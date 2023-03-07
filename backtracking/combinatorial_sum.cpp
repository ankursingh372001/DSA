#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<vector<int>> ans;
    vector<int> curr;
    
    void f(vector<int>& arr, int n, int target) {
        
        if(target == 0) {
            
            ans.push_back(curr);
            return;
        }
        
        if(n == 0) {
            
            return;
        }
        
        if(arr[n - 1] > target) {
            
            f(arr, n - 1, target);
            return;
        }
            
        curr.push_back(arr[n - 1]);
            
        f(arr, n, target - arr[n - 1]);
            
        curr.pop_back();
        
        f(arr, n - 1, target);
    }
    
    vector<vector<int> > combinationSum(vector<int> &A, int B) {

        set<int> st(A.begin(), A.end());
        A.clear();
        
        for(int x: st) 
            A.push_back(x);

        reverse(A.begin(), A.end());
        
        int n = A.size();
        
        f(A, n, B);
        
        return ans;
    }
};

// https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article