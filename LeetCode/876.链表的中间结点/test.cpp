#include "../list.h"

using namespace std;

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast{head};
        ListNode* slow{head};

        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};


int main() {
    string line = "[1,2,3,4,5,6]";
    ListNode* head = stringToListNode(line);
    prettyPrintLinkedList(head);

    Solution so;
    auto ans = so.middleNode(head);
    prettyPrintLinkedList(ans);
    
    return 0;
}