#include<bits/stdc++.h>
using namespace std;

vector<int> prevMinIdx(vector<int>& arr, int n) {

    vector<int> ans(n);

    stack<int> st;
    st.push(-1);
    
    for(int i = 0; i < n; ++i) {

        while(st.top() != -1 && arr[st.top()] >= arr[i]) st.pop();
        ans[i] = st.top();
        st.push(i);
    }
    
    return ans;
}

vector<int> nextMinIdx(vector<int>& arr, int n) {
    
    vector<int> ans(n);
    
    stack<int> st;
    st.push(n);
    
    for(int i = n - 1; i >= 0; --i) {

        while(st.top() != n && arr[st.top()] >= arr[i]) st.pop();
        ans[i] = st.top();
        st.push(i);
    }
    
    return ans;
}

int largestRectangleArea(vector<int>& heights, int n) {
    
    vector<int> A = prevMinIdx(heights, n);
    vector<int> B = nextMinIdx(heights, n);
    
    int area = INT_MIN;
    
    for(int i = 0; i < n; ++i) 
        area = max(area, heights[i] * (B[i] - A[i] - 1));
    
    return area;
}

int maxArea(vector<vector<int>>& matrix, int m, int n) {
    
    vector<int> heights(m, 0);
    
    int ans = INT_MIN;
    
    for(int i = 0; i < n; ++i) {

        for(int j = 0; j < m; ++j)
            heights[j] = (matrix[i][j] == 0 ? 0 : heights[j] + 1);
        
        ans = max(ans, largestRectangleArea(heights, m));
    }
    
    return ans;
}