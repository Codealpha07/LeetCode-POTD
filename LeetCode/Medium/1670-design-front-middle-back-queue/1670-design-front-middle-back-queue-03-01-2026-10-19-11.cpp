#include <bits/stdc++.h>
using namespace std;

class FrontMiddleBackQueue {
public:
    
    deque<int> l, r;
    
    void balance(){
        if(l.size() > r.size() + 1){
            r.push_front(l.back());
            l.pop_back();
        }
        else if(l.size() < r.size()){
            l.push_back(r.front());
            r.pop_front();
        }
    }
    
    FrontMiddleBackQueue() {
        
    }
    
    void pushFront(int val) {
        l.push_front(val);
        balance();
    }
    
    void pushMiddle(int val) {
        if(l.size() > r.size()){
            r.push_front(l.back());
            l.pop_back();
        }
        l.push_back(val);
    }
    
    void pushBack(int val) {
        r.push_back(val);
        balance();
    }
    
    int popFront() {
        if(l.empty() && r.empty()) return -1;
        
        int ans;
        if(!l.empty()){
            ans = l.front();
            l.pop_front();
        }
        else{
            ans = r.front();
            r.pop_front();
        }
        
        balance();
        return ans;
    }
    
    int popMiddle() {
        if(l.empty() && r.empty()) return -1;
        
        int ans = l.back();
        l.pop_back();
        balance();
        return ans;
    }
    
    int popBack() {
        if(l.empty() && r.empty()) return -1;
        
        int ans;
        if(!r.empty()){
            ans = r.back();
            r.pop_back();
        }
        else{
            ans = l.back();
            l.pop_back();
        }
        
        balance();
        return ans;
    }
};