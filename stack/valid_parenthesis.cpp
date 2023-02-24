#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {

    stack<char> st;
    
    for(char& x: s) {

        if(x == '(' || x == '{' || x == '[') st.push(x);
        else if(x == ')' && st.size() > 0 && st.top() == '(') st.pop();
        else if(x == '}' && st.size() > 0 && st.top() == '{') st.pop();
        else if(x == ']' && st.size() > 0 && st.top() == '[') st.pop();
        else return false;
    }
    
    if(st.size() > 0) return false;
    
    return true;
}

// https://leetcode.com/problems/valid-parentheses/description/