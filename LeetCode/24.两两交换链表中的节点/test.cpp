#include "../list.h"

using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head) return nullptr;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *p = dummy;

        while(p->next != nullptr && p->next->next != nullptr) {
            ListNode* firstNode = p->next;
            ListNode* secondNode = firstNode->next;

            p->next = secondNode;
            firstNode->next = secondNode->next;
            secondNode->next = firstNode;
            p = firstNode;
        }
        return dummy->next;
    }
};


int main() {
    string line = "[1,2,3,4,5]";
    ListNode* head = stringToListNode(line);
    prettyPrintLinkedList(head);

    Solution so;
    auto ans = so.swapPairs(head);
    prettyPrintLinkedList(ans);
    
    return 0;
}