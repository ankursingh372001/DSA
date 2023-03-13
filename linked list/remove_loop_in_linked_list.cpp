#include<bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int data;
    ListNode *next;

    ListNode() {
        next = NULL;
    }
};

void removeLoop(ListNode* head) {

    ListNode* prev = NULL;
    ListNode* slow = head;
    ListNode* fast = head;
    
    while(fast && fast->next) {
        
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
        
        if(fast == slow) {
            
            fast = head;
            
            while(slow != fast) {
                
                prev = slow;
                slow = slow->next;
                fast = fast->next;
            }
            
            prev->next = NULL;
        }
    }
}