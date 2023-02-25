#include<bits/stdc++.h>
using namespace std;

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3) {
           
    vector<int> ans;

    int i = 0;
    int j = 0;
    int k = 0;
    
    while(i < n1 && j < n2 && k < n3) {
        
        if(A[i] == B[j] && A[i] == C[k]) {

            if(ans.empty() || ans.back() != A[i]) ans.push_back(A[i]); 
            i++,j++,k++;
        }
        else if(A[i] < B[j]) i++;
        else if(B[j] < C[k]) j++;
        else k++;
    }
    
    return ans;
}

// https://practice.geeksforgeeks.org/problems/common-elements1132/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article