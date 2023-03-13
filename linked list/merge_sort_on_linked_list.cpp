#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sort-list/

class ListNode {
public:
    int data;
    ListNode *next;

    ListNode(int data) {
        this->data = data;
        next = NULL;
    }
};

ListNode* mergeTwoSortedLinkedList(ListNode* head1, ListNode* head2) {
    
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;

    ListNode *head = new ListNode(-1);
    ListNode *curr = head;
    
    while(head1 && head2) {

        if(head1->data <= head2->data) {

            curr->next = head1;
            head1 = head1->next;
        }
        else {

            curr->next = head2;
            head2 = head2->next;
        }

        curr = curr->next;
    }
    
    if(head1) curr->next = head1;
    if(head2) curr->next = head2;

    return head->next;
}

ListNode* findMiddleNode(ListNode* head) {
    
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast->next && fast->next->next) {
        
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

ListNode* mergeSort(ListNode* head) {
    
    if(head == NULL || head->next == NULL)
        return head;
    
    ListNode* midd = findMiddleNode(head);

    ListNode* temp = midd->next;

    midd->next = NULL;
    
    head = mergeSort(head);
    temp = mergeSort(temp);
        
    return mergeTwoSortedLinkedList(head, temp);
}