#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reorder-list/description/

class ListNode {
public:
    int data;
    ListNode *next;
    
    ListNode(int data) {

        this->data = data;
        next = NULL;
    }
};

ListNode* findMiddleNode(ListNode* head) {
    
    if(head == NULL || head->next == NULL)
        return head;
        
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast && fast->next) {
        
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

ListNode* reverse(ListNode* head) {
    
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

void reorderList(ListNode* head) {
    
    if(head == NULL || head->next == NULL || head->next->next == NULL)
        return;
    
    ListNode* midd = findMiddleNode(head);
    
    ListNode* curr1 = head;
    ListNode* curr2 = reverse(midd->next);
    
    midd->next = NULL;
    
    while(curr2) {
        
        ListNode* temp1 = curr1->next;
        ListNode* temp2 = curr2->next;
        
        curr1->next = curr2;
        curr1->next->next = temp1;
        
        curr1 = temp1;
        curr2 = temp2;
    }
}