#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* runner = head;
    
    if (runner->next == nullptr) return nullptr;
    
    for(int i = 0; i < n; i++) 
        runner = runner->next;
    
    if (runner == nullptr) return head->next;       // delete at front
    
    ListNode* prev = nullptr;
    ListNode* curr = head;
    
    while(runner != nullptr) {
        prev = curr;
        curr = curr->next;
        runner = runner->next;
    }
    
    prev->next = curr->next;
    
    return head;
}


// linked list, two pointers