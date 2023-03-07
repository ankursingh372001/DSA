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

Node* reverseList(Node* head) {
        
    Node* prev = NULL;
    Node* curr = head;
    Node* next = head->next;
    
    while(curr) {
        
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

// https://leetcode.com/problems/reverse-linked-list/