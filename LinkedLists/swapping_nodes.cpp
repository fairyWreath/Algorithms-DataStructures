#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };



// change in pla
 ListNode* swapNodes(ListNode* head, int k) {
    ListNode* front = nullptr;
    ListNode* back = head;
    
    ListNode* runner = head;
    
    ListNode* frontprev = nullptr;
    for(int i = 1; i < k; i++) {
        frontprev = runner;
        runner = runner->next;
    }
    front = runner;
    
    ListNode* backprev = nullptr;
    while(runner->next != nullptr) {
        backprev = back;
        runner = runner->next;
        back = back->next;
    }
    
    if (front == back) return head;
    
    // swap in place
    //swap(front->val, back->val);

    if (back != frontprev && frontprev != nullptr) frontprev->next = back;
    ListNode* temp = back->next;

    if (front->next != back) back->next = front->next;
    else back->next = front;

    if(front != backprev && backprev != nullptr) backprev->next = front;
    if (front != temp) front->next = temp;
    else front->next = back;

    if(head == front) return back;
    if(head == back) return front;

    return head;
}

int main() {
    ListNode* start = new ListNode(90);
    start->next = new ListNode(100);

    cout << start->val << endl;

    swapNodes(start, 2);

    cout << endl;
    while(start != nullptr) {
        cout << start->val << "->";
        start = start->next;
    }
}