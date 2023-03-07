#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    
    MedianFinder() {}    
    
    void addNum(int num) {
        
        pq2.push(num);
        
        if(pq1.size() < pq2.size()) {
            
            int x = pq2.top();
            pq2.pop();
            
            pq1.push(x);
        }
        else if(pq1.size() == pq2.size() && pq1.top() > pq2.top()) {
            
            int x = pq1.top();
            pq1.pop();
            
            int y = pq2.top();
            pq2.pop();
            
            pq1.push(y);
            pq2.push(x);
        }
    }
    
    double findMedian() {
        
        if((pq1.size() + pq2.size()) & 1)
            return pq1.top();
        
        return (pq1.top() + pq2.top()) * 1.0 / 2;
    }
};