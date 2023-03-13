#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int data;
    ListNode *next;

    ListNode(int data) {
        this->data = data;
        next = NULL;
    }
};

ListNode* reverseList(ListNode* head) {
    
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = NULL;
    
    while(curr) {
        
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

ListNode *compute(ListNode *head) {
    
    if(head == NULL || head->next == NULL)
        return head;
        
    head = reverseList(head);
    
    ListNode* curr = head;
    
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