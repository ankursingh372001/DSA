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

Node * removeDuplicates(Node *head) {
        
    set<int> st;
    
    Node* curr = head;
    Node* prev = NULL;
    
    while(curr) {

        if(st.find(curr->data) == st.end()) {

            st.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
        else {

            prev->next = curr->next;
            curr = curr->next;
        }
    }
    
    return head;
}

// https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article