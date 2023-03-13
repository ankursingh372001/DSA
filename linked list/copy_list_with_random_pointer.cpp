#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/copy-list-with-random-pointer/

class ListNode {
public:
    int data;
    ListNode *next;
    ListNode *random;

    ListNode(int data) {
        this->data = data;
        next = NULL;
        random = NULL;
    }
};

ListNode* copyRandomList(ListNode* head) {
    
    if(head == NULL)
        return NULL;
    
    ListNode* curr = head;
    
    while(curr) {
        
        ListNode* temp = new ListNode(curr->data);
        temp->next = curr->next;
        curr->next = temp;
        curr = temp->next;
    }
    
    curr = head;
    
    while(curr) {
        
        curr->next->random = (curr->random ? curr->random->next : NULL);
        curr = curr->next->next;
    }
    
    curr = head;
    
    ListNode* Head = new ListNode(-1);
    ListNode* Curr = Head;
    
    while(curr) {
        
        Curr->next = curr->next;
        Curr = Curr->next;
        
        curr->next = curr->next->next;
        
        curr = curr->next;
        Curr->next = NULL;
    }
    
    return Head->next;
}