#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    
    Node(int data) {

        this->data = data;
        next = NULL;
    }
};

const int MOD = 1e9 + 7;

int f(Node* head) {

    long long x = 0;

    while(head) {

        x *= 10;
        x += head->data;
        x %= MOD;
        head = head->next;
    }

    return x;
}

long long  multiplyTwoLists (Node* head1, Node* head2) {
    
    long long x = f(head1);
    long long y = f(head2);
    
    return (x * y) % MOD; 
}

// https://practice.geeksforgeeks.org/problems/multiply-two-linked-lists/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article