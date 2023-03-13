#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/linked-list-cycle/description/

class ListNode {
public:
    int data;
    ListNode *next;

    ListNode() {
        next = NULL;
    }
};

bool checkCycle(ListNode *head) {

    ListNode* slow = head;
    ListNode* fast = head;
        
    while (fast && fast->next) {
        
        slow = slow->next;
        fast = fast->next->next;
    
        if(slow == fast)
            return true;
    }
        
    return false;
}
