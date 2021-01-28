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


// O(n) time AND memory
ListNode* sortList(ListNode* head) {
    if (head == nullptr) return head;
    
    vector<int> arr;
    ListNode* root = head;
    ListNode* res = root;
    
    while(head != nullptr) {
        arr.push_back(head->val);
        head = head->next;
    }
    
    std::sort(arr.begin(), arr.end());
    
    for(int& i : arr) {
        root->val = i;
        root = root->next;
    }
    
    return res;
}