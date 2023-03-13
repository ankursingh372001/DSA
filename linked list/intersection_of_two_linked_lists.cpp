#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/intersection-of-two-linked-lists/

class ListNode {
public:
    int data;
    ListNode *next;

    ListNode() {
        next = NULL;
    }
};

int getLength(ListNode* head) {

    if(head == NULL)
        return 0;

    return 1 + getLength(head->next);
}

ListNode* getNthNode(ListNode* head, int n) {

    if(n == 0)
        return head;

    if(head == NULL)
        return head;

    return getNthNode(head->next, n - 1);
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    int m = getLength(headA);
    int n = getLength(headB);
    
    if(m > n)
        headA = getNthNode(headA, m - n);
    
    if(n > m)
        headB = getNthNode(headB, n - m);
    
    while(headA && headB && headA != headB) {

        headA = headA->next;
        headB = headB->next;
    }
    
    if(headA == headB)
        return headA;
    
    return NULL;
}