#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node() {
        next = NULL;
    }
};

bool checkCycle(Node *head) {

    Node* slow = head;
    Node* fast = head;
        
    while (fast && fast->next) {
        
        slow = slow->next;
        fast = fast->next->next;
    
        if(slow == fast)
            return true;
    }
        
    return false;
}


// https://leetcode.com/problems/linked-list-cycle/description/