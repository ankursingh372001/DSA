#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    
    Node(int data) {

        this->data = data;
        next = NULL;
    }
};

Node* divide(int N, Node *head){
        
    vector<Node*> Head(2, NULL);
    vector<Node*> Tail(2, NULL);
    
    Node* curr = head;
    while(curr) {
        
        if(Head[curr->data & 1]) {
            
            Tail[curr->data & 1]->next = curr;
            Tail[curr->data & 1] = curr;
        }
        else {
            
            Head[curr->data & 1] = curr;
            Tail[curr->data & 1] = curr;
        }
        
        curr = curr->next;
    }
    
    head = new Node(-1);
    curr = head;
    
    curr->next = Head[0];
    
    if(Tail[0]) curr = Tail[0];
    
    curr->next = Head[1];
    
    if(Tail[1]) curr = Tail[1];
    
    curr->next = NULL;
    
    return head->next;
}
// https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1