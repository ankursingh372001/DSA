#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/add-two-numbers/

class ListNode {
public:
    int data;
    ListNode *next;

    ListNode(int data) {
        this->data = data;
        next = NULL;
    }
};

ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
    
    ListNode* head = new ListNode(-1);
    ListNode* curr = head;
    
    int carry = 0;
    
    while(head1 || head2 || carry) {
        
        int sum = 0;
        
        if(head1) {
            
            sum += head1->data;
            head1 = head1->next;
        }
        
        if(head2) {
            
            sum += head2->data;
            head2 = head2->next;
        }
        
        sum += carry;
        
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
        
        carry = sum / 10;
    }
    
    return head->next;
}