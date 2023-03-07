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

Node* segregate(Node *head) {
    
    vector<Node*> Head(3, NULL);
    vector<Node*> Tail(3, NULL);
    
    Node* curr = head;
    while(curr) {
        
        if(Head[curr->data] == NULL) {
            
            Head[curr->data] = curr;
            Tail[curr->data] = curr;
        }
        else {
            
            Tail[curr->data]->next = curr;
            Tail[curr->data] = curr;
        }
            
        curr = curr->next;
    }
    
    head = new Node(-1);
    curr = head;

    
    curr->next = Head[0];
    
    if(Tail[0]) curr = Tail[0];
    
    curr->next = Head[1];
    
    if(Tail[1]) curr = Tail[1];
    
    curr->next = Head[2];
    
    if(Tail[2]) curr = Tail[2];
    
    curr->next = NULL;
    
    return head->next;
}