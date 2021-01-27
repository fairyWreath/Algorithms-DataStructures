#include <vector>

using namespace std;

class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        deque.resize(k+1);      // one extra sacrificed
        front = 0;
        rear = 0;
        capacity = k + 1;       
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) return false;
        int newfront = front - 1;
        if (newfront < 0) newfront = capacity - 1;
        deque[newfront] = value;
        front = newfront;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) return false;
        deque[rear] = value;
        rear = (rear + 1) % capacity;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) return false;
        rear = rear - 1;
        if (rear < 0) rear = capacity - 1;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) return -1;
        return deque[front];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) return -1;
        
        if (rear > 0) return deque[rear - 1];
        return deque[capacity - 1];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        if (size() == 0) return true;
        return false;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        if (size() == capacity - 1) return true;
        return false;
    }
    
    int size() {
        return (capacity - front + rear) % capacity;
    }
    
    
    vector<int> deque;
    int front;
    int rear;
    int capacity;
};


// queues, design