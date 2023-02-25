#include<bits/stdc++.h>
using namespace std;

vector<int> prevMinIdx(vector<int>& arr, int n) {

    vector<int> ans(n);

    stack<vector<int>> st;
    st.push({INT_MIN, -1});
    
    for(int i = 0; i < n; ++i) {

        while(st.top()[0] >= arr[i]) st.pop();

        ans[i] = st.top()[1];
        
        st.push({arr[i], i});
    }
    
    return ans;
}

vector<int> nextMinIdx(vector<int>& arr, int n) {
    
    vector<int> ans(n);
    
    stack<vector<int>> st;
    st.push({INT_MAX, n});
    
    for(int i = n - 1; i >= 0; --i) {

        while(st.top()[0] >= arr[i]) st.pop();
        
        ans[i] = st.top()[1];
        
        st.push({arr[i], i});
    }
    
    return ans;
}

int largestRectangleArea(vector<int>& heights, int n) {
    
    vector<int> A = prevMinIdx(heights, n);
    vector<int> B = nextMinIdx(heights, n);
    
    int ans = INT_MIN;
    
    for(int i = 0; i < heights.size(); ++i) 
        ans = max(ans, heights[i] * (B[i] - A[i] - 1));
    
    return ans;
}

// https://leetcode.com/problems/largest-rectangle-in-histogram/description/