#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node() {
        next = NULL;
    }
};

Node* removeNthFromEnd(Node* head, int n) {
        
    Node* prev = NULL;
    Node* curr = head;
    Node* next = head;
    
    for(int i = 0; i < n; ++i)
        next = next->next;
    
    while(next) {
        
        prev = curr;
        curr = curr->next;
        next = next->next;
    }
    
    if(prev)
        prev->next = curr->next;
    else
        head = head->next;
    
    return head;
}