#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reverse-linked-list/

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
        
    if(head == NULL || head->next == NULL)
        return head;

    ListNode* prev = NULL;
    ListNode* curr = head;
    
    while(curr) {
        
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}