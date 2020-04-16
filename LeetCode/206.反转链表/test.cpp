#include "../list.h"

using namespace std;
//递归
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        if (head->next == nullptr) return head;
        auto last = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
};


int main() {
    string line = "[1,2,3,4,5]";
    ListNode* head = stringToListNode(line);
    prettyPrintLinkedList(head);

    Solution so;
    auto ans = so.reverseList(head);
    prettyPrintLinkedList(ans); 
    
    return 0;
}