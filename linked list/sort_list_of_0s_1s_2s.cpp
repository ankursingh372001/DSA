#include<bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

class ListNode {
public:
    int data;
    ListNode *next;
    
    ListNode(int data) {

        this->data = data;
        next = NULL;
    }
};

ListNode* segregate(ListNode *head) {
    
    vector<ListNode*> Head(3, NULL);
    vector<ListNode*> Tail(3, NULL);
    
    ListNode* curr = head;
    while(curr) {
        
        if(Head[curr->data] == NULL) {
            
            Head[curr->data] = curr;
            Tail[curr->data] = curr;
        }
        else {
            
            Tail[curr->data]->next = curr;
            Tail[curr->data] = curr;
        }
            
        curr = curr->next;
    }
    
    head = new ListNode(-1);
    curr = head;

    
    curr->next = Head[0];
    if(Tail[0]) 
        curr = Tail[0];
    
    curr->next = Head[1];
    if(Tail[1]) 
        curr = Tail[1];
    
    curr->next = Head[2];
    if(Tail[2]) 
        curr = Tail[2];
    
    curr->next = NULL;
    
    return head->next;
}
