#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node() {
        next = NULL;
    }

    Node(int data) {
        this->data = data;
    }
};

Node* mergeList(Node* head1, Node* head2) {

    Node* head = new Node(-1);
    Node* curr = head;

    while(head1 && head2) {

        if(head1->data <= head2->data) {

            curr->next = head1;
            curr = curr->next;
            head1 = head1->next;
        }
        else {

            curr->next = head2;
            curr = curr->next;
            head2 = head2->next;
        }
    }

    if(head1)
	    curr->next = head1;

    if(head2)
	    curr->next = head2;

    return head->next;
}

// https://leetcode.com/problems/merge-two-sorted-lists/