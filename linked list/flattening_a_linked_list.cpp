#include<bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class ListNode {
public:
    int data;
    ListNode *next;
    ListNode *bottom;

    ListNode(int data) {
        this->data = data;
        next = NULL;
        bottom = NULL;
    }
};

ListNode* mergeList(ListNode* head1, ListNode* head2) {

    if(head1 == NULL)
        return head2;
        
    if(head2 == NULL)
        return head1;
        
    ListNode* head = new ListNode(-1);
    ListNode* curr = head;
    
    while(head1 && head2) {

        if(head1->data <= head2->data) {

            curr->bottom = head1;
            head1 = head1->bottom;
        }
        else {
            curr->bottom = head2;
            head2 = head2->bottom;
        }

        curr = curr->bottom;
    }
    
    if(head1)
        curr->bottom = head1;
    
    if(head2)
        curr->bottom = head2;
        
    return head->bottom;
}

ListNode *flatten(ListNode *root) {

    if(root == NULL)
        return root;
        
    ListNode* ans = root;
    ListNode* curr = root->next;
    
    while(curr) {

        ans = mergeList(ans, curr);
        curr = curr->next;
    }
    
    return ans;
}