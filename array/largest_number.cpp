#include<bits/stdc++.h>
using namespace std;

static bool comp(const string& s, const string& t) {

    string a = s + t;
    string b = t + s;

    return a < b;
}

string largestNumber(int arr[], int n) {

    string temp[n];

    for(int i = 0; i < n; ++i) temp[i] = to_string(arr[i]);

    sort(temp, temp + n, comp);

    string ans =  "";
    
    for(int i = n - 1; i >= 0; --i) ans += temp[i];

    if(ans[0] == '0') return "0";

    return ans;
}