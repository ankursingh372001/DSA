#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

class ListNode {
public:
    int data;
    ListNode *next;

    ListNode() {
        next = NULL;
    }
};

int getListLength(ListNode* head) {
    
    if(head == NULL)
        return 0;
    
    return 1 + getListLength(head->next);
}

// 0-based indexing
ListNode* getNthNode(ListNode* head, int n) {
    
    if(n == 0)
        return head;
    
    if(head == NULL)
        return NULL;
    
    return getNthNode(head->next, n - 1);
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    
    int length = getListLength(head);
    
    if(n == length) 
        return head->next;
    
    ListNode* prev = getNthNode(head, length - n - 1);
    
    prev->next = prev->next->next;
    
    return head;
}