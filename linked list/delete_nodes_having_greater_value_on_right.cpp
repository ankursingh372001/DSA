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

Node* reverseList(Node* head) {
    
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;
    
    while(curr) {
        
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

Node *compute(Node *head) {
    
    if(head == NULL || head->next == NULL)
        return head;
        
    head = reverseList(head);
    
    Node* curr = head;
    
    while(curr->next) {
        
        if(curr->next->data < curr->data) {
            
            curr->next = curr->next->next;
        }    
        else {
            
            curr = curr->next;
        }
    }
    
    head = reverseList(head);
    
    return head;
}

// https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article