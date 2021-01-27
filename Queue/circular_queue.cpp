#include <vector>

using namespace std;

class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        queue = new int[k + 1];     // one extra sacrificed
        front = 0;
        rear = 0;
        capacity = k + 1;
    }
    
    ~MyCircularQueue() {
      delete [] queue;  
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        queue[rear] = value;
        rear = (rear + 1) % capacity;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        // queue[front] = nulllll
        front = (front + 1) % capacity;
        return true;
    }
    
    int Front() {
        if (isEmpty())
            return -1;
        
        return queue[front];
    }
    
    int Rear() {
        if (isEmpty())
            return -1;
       
        if (rear > 0)
            return queue[rear - 1];
        else
            return queue[capacity - 1];
    }
    
    bool isEmpty() {
        if (size() == 0)
            return true;
        return false;
    }
    
    bool isFull() {
        if (size() == capacity - 1)
            return true;
        return false;
    }
    
    int size() {
        return (capacity - front + rear) % capacity;
    }
    
    int* queue;
    int front;
    int rear;
    int capacity;
};


// top 99.85% compared to top 5/6% with pointer array

class MyCircularQueue2{
public:
    MyCircularQueue2(int k) {
        queue.resize(k+1);
        front = 0;
        rear = 0;
        capacity = k + 1;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        queue[rear] = value;
        rear = (rear + 1) % capacity;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        // queue[front] = nulllll
        front = (front + 1) % capacity;
        return true;
    }
    
    int Front() {
        if (isEmpty())
            return -1;
        
        return queue[front];
    }
    
    int Rear() {
        if (isEmpty())
            return -1;
       
        if (rear > 0)
            return queue[rear - 1];
        else
            return queue[capacity - 1];
    }
    
    bool isEmpty() {
        if (size() == 0)
            return true;
        return false;
    }
    
    bool isFull() {
        if (size() == capacity - 1)
            return true;
        return false;
    }
    
    int size() {
        return (capacity - front + rear) % capacity;
    }
    
   
    vector<int> queue;
    int front;
    int rear;
    int capacity;
};