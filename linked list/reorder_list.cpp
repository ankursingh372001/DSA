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

class Solution {
public:
    
    Node* findMiddleNode(Node* head) {
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast && fast->next) {
            
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    Node* reverse(Node* head) {
        
        if(head == NULL || head->next == NULL)
            return head;
            
        Node* prev = NULL;
        Node* curr = head;
        Node* next = head->next;
        
        while(curr) {
            
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    void reorderList(Node* head) {
        
        if(head == NULL || head->next == NULL || head->next->next == NULL)
            return;
        
        Node* midd = findMiddleNode(head);
        
        Node* tail = head;
        while(tail->next != midd)
            tail = tail->next;
        
        tail->next = NULL;
        
        Node* curr1 = head;
        Node* curr2 = reverse(midd);
        
        Node* ans = head;
        curr1 = curr1->next;
        
        Node* curr = ans;
        
        while(curr1 && curr2) {
            
            curr->next = curr2;
            curr = curr->next;
            curr2 = curr2->next;
            
            curr->next = curr1;
            curr = curr->next;
            curr1 = curr1->next;
        }
        
        curr->next = curr2;
        
        head = ans;
    }
};

https://leetcode.com/problems/reorder-list/description/