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

Node* mergeKLists(vector<Node*>& lists) {
    
    Node* head = NULL;
    Node* curr = NULL;
    
    priority_queue<pair<int, Node*>, vector<pair<int, Node*>>, greater<pair<int,Node*>>> pq;
    
    for(int i=0; i<lists.size(); ++i)
        if(lists[i] != NULL)
            pq.push(make_pair(lists[i]->data, lists[i]));
    
    while(!pq.empty())
    {
        Node* temp = pq.top().second;
        pq.pop();
        
        if(temp->next != NULL)
            pq.push(make_pair(temp->next->data, temp->next));
        
        if(head == NULL)
        {
            head = temp;
            curr = temp;
        }
        else
        {
            temp->next = NULL;
            curr->next = temp;
            curr = temp;
        }
    }
    
    return head;
}