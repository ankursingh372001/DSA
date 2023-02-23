#include<bits/stdc++.h>
using namespace std;

bool isNotAlphaNumeric(char c) {

    bool check = !((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));

    return check;
}

bool isPalindrome(string s) {
    
    int i = 0;
    int j = s.length() - 1;
    
    while(i < j) {

        if(isNotAlphaNumeric(s[i])) i++;
        else if(!isNotAlphaNumeric(s[j])) j--;
        else if(tolower(s[i]) != tolower(s[j])) return false;
        else i++, j--;
    }
    
    return true;
}