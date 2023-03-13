#include<bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

class DLLNode {
public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int data) {

        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

DLLNode* reverseDLL(DLLNode * head) {
    
    DLLNode* prev = NULL;
    DLLNode* curr = head;
    
    while(curr) {
        
        DLLNode* next = curr->next;
        
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }
    
    return prev;
}