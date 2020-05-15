#include "../list.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = dummy;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            if (cur->next->val == cur->next->next->val) {
                ListNode* temp = cur->next;
                while (temp != nullptr && temp->next != nullptr && temp->val == temp->next->val ) {
                    temp = temp->next;
                }
                cur->next = temp->next;
                delete temp;
            } 
            else
                cur = cur->next;
        }
        return dummy->next;
    }
};

int main() {
    string line = "[1,2,3,3,4,4,5]";
    ListNode* head = stringToListNode(line);
    prettyPrintLinkedList(head);

    Solution so;
    auto ans = so.deleteDuplicates(head);
    prettyPrintLinkedList(ans); 
    
    return 0;
}