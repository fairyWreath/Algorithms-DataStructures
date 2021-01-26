#include <vector>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* root = head;
        ListNode* prev = head;
        
 
        ListNode* evenstart = new ListNode();
               ListNode* evens = evenstart;
        
        int count = 1;
        
        while(head != nullptr) {
            if (count % 2 == 0) {
                evens->next = head;   
                evens = evens->next;
                
                if(head->next != nullptr)
                    prev->next = head->next;
            }
            else {
                prev = head;
            }
            
            head = head->next;
            count++;
        }
        
        evens->next = nullptr;
        
        
        // for linked list always ensure that node is not null
        if (prev != nullptr)
            prev->next = evenstart->next;
        
        return root;
    }
};