#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    
    bool f(int a[], int n, int k, int target, int reqd, int idx) {
        
        if(k == 0)
            return true;
            
        if(reqd == 0)
            return f(a, n, k - 1, target, target, n - 1);
            
        if(idx < 0)
            return false;
            
        if(a[idx] == 0)
            return f(a, n, k, target, reqd, idx - 1);
            
        if(a[idx] > reqd) 
            return f(a, n, k, target, reqd, idx - 1);
        
        if(f(a, n, k, target, reqd, idx - 1))
            return true;
        
        int temp = a[idx];
        
        a[idx] = 0;
        
        if(f(a, n, k, target, reqd - temp, idx - 1))
            return true;
            
        a[idx] = temp;
        
        return false;
    }  
    
    bool isKPartitionPossible(int a[], int n, int k) {
        
        int sum = accumulate(a, a + n, 0);
        
        if(sum % k != 0)
            return false;
        
        return f(a, n, k, sum / k, sum / k, n);
    }
};