#include<bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

class ListNode {
public:
    int data;
    ListNode *next;

    ListNode() {
        next = NULL;
    }
};

ListNode * removeDuplicates(ListNode *head) {
        
    set<int> st;
    
    ListNode* curr = head;
    ListNode* prev = NULL;
    
    while(curr) {

        if(st.find(curr->data) == st.end()) {

            st.insert(curr->data);
            prev = curr;
        }
        else {

            prev->next = curr->next;
        }

        curr = curr->next;
    }
    
    return head;
}
