#include <queue>

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
                
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        while(!mainqueue.empty()) {
            auxqueue.push(mainqueue.front());
            mainqueue.pop();
        }
        mainqueue.push(x);
        while(!auxqueue.empty()) {
            mainqueue.push(auxqueue.front());
            auxqueue.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int front = mainqueue.front();
        mainqueue.pop();
        return front;
    }
    
    /** Get the top element. */
    int top() {
        return mainqueue.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return mainqueue.empty();
    }
    
    queue<int> mainqueue;
    queue<int> auxqueue;
};



// stack. design