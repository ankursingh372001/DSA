#include<bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/linked-list-in-zig-zag-fashion/1

class ListNode {
public:
    int data;
    ListNode *next;

    ListNode() {
        next = NULL;
    }
};

ListNode *zigZag(ListNode* head) {
    
    ListNode* curr = head;
    
    int idx = 0;
    
    while(curr && curr->next) {
        
        if(idx & 1) {
            
            if(curr->data < curr->next->data) {
                
                swap(curr->data, curr->next->data);
            }
        }
        else {
            
            if(curr->data > curr->next->data) {
                
                swap(curr->data, curr->next->data);
            }
        }
        
        curr = curr->next;
        idx++;    
    }
    
    return head;
}