#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<int> intervals[], int n) {
    
    sort(intervals, intervals + n);
     
    vector<vector<int>> ans;

    ans.push_back(intervals[0]);

    for (int i = 1; i < n; ++i) {

        if (ans.back()[1] < intervals[i][0] - 1) ans.push_back(intervals[i]); 
        else ans.back()[1] = max(ans.back()[1], intervals[i][1]);
    }
 
    return ans;
}

// https://leetcode.com/problems/merge-intervals/description/
