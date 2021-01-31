#include <vector>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        while (!mainstack.empty()) {
            auxstack.push_back(mainstack.back());
            mainstack.pop_back();
        }
        mainstack.push_back(x);
        while(!auxstack.empty()) {
            mainstack.push_back(auxstack.back());
            auxstack.pop_back();
        }
        
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int back = mainstack.back();
        mainstack.pop_back();
        return back;
    }
    
    /** Get the front element. */
    int peek() {
        return mainstack.back();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return mainstack.empty();
    }
    
    vector<int> mainstack;
    vector<int> auxstack;
};

// queues, design