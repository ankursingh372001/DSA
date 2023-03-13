#include<bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/subtraction-in-linked-list/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

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
    
    while(curr) {
        
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

int getListLength(ListNode* head) {
    
    if(head == NULL)
        return 0;
        
    return 1 + getListLength(head->next);
}

ListNode* subtract(ListNode* l1, ListNode* l2) {
    
    l1 = reverseList(l1);
    l2 = reverseList(l2);
    
    ListNode* head = new ListNode(-1);
    ListNode* curr = head;
    
    int borrow = 0;
    
    while(l1 || l2) {
        
        int a = (l1 ? l1->data : 0) + borrow;
        int b = (l2 ? l2->data : 0);
        
        if(a < b) {
            
            a += 10;
            borrow = -1;
        }
        else {
            
            borrow = 0;
        }
        
        curr->next = new ListNode(a - b);
        curr = curr->next;
        
        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }
    
    head = reverseList(head->next);
    
    while(head && head->data == 0)
        head = head->next;
    
    if(head == NULL)
        return new ListNode(0);
        
    return head;
}

bool isFirstListGreater(ListNode* l1, ListNode* l2) {
    
    int n = getListLength(l1);
    int m = getListLength(l2);
    
    if(n > m)
        return true;
        
    if(n < m)
        return false;
        
    while(l1 && l2) {
        
        if(l1->data > l2->data)
            return true;
            
        if(l1->data < l2->data)
            return false;
            
        l1 = l1->next;
        l2 = l2->next;
    }
    
    return false;
}

ListNode* subLinkedList(ListNode* l1, ListNode* l2) {
    
    while(l1 && l1->data == 0)
        l1 = l1->next;
        
    while(l2 && l2->data == 0)
        l2 = l2->next;
        
    ListNode* head = (isFirstListGreater(l1, l2) ? subtract(l1, l2) : subtract(l2, l1));
    
    return head;
}