#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/merge-two-sorted-lists/

class ListNode {
public:
    int data;
    ListNode *next;

    ListNode() {
        next = NULL;
    }

    ListNode(int data) {
        this->data = data;
    }
};

ListNode* mergeList(ListNode* head1, ListNode* head2) {

    ListNode* head = new ListNode(-1);
    ListNode* curr = head;

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

    if(head1)
	    curr->next = head1;

    if(head2)
	    curr->next = head2;

    return head->next;
}