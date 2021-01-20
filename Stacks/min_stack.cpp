#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        
        long long xlong = x;
        
        if (stack.empty())
        {
            stack.push(xlong);
            minEle = xlong;
            return;
        }
        
    
            if(xlong < minEle)  {
                stack.push(2*xlong - minEle);
                minEle = xlong;
            }
            else
                stack.push(xlong);
    }
    
    void pop() {
    
        long long back = stack.top();
        stack.pop();
    
        if (back < minEle) 
            minEle = 2*minEle - back;
    }
    
    int top() {
        if (stack.top() < minEle) return minEle;
        return stack.top();
    }
    
    int getMin() {
        return minEle;
    }
    
    stack<long long> stack;
    long long minEle;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */