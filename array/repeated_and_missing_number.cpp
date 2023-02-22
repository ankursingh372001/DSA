#include<bits/stdc++.h>
using namespace std;

// https://www.interviewbit.com/problems/repeat-and-missing-number-array/

vector<int> repeatedNumber(vector<int> &arr) {
    
    int n = arr.size();
    
    long long linSum = 0;
    long long sqrSum = 0;
    
    for(int i = 0; i < n; ++i) {
        
        linSum += arr[i];
        sqrSum += arr[i] * 1ll * arr[i];
    }
    
    long long a = n * 1ll * (n + 1) / 2;
    long long b = n * 1ll * (n + 1) * (2 * n + 1) / 6;
    
    // let repeated number be be x and missing number be y
    int xminusy = linSum - a; 
    int xplusy = (sqrSum - b) / xminusy;
    
    int x = (xplusy + xminusy) / 2;
    int y = (xplusy - x);
    
    return {x, y};
}
