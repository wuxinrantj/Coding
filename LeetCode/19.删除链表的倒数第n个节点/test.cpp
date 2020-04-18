#include "../list.h"

using namespace std;

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0);  //哑节点
        dummy->next = head;
        ListNode* fast{dummy};
        ListNode* slow{dummy};
        while(n-- > 0) {
            fast = fast->next;
        }
        while(fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};


int main() {
    string line = "[1,2,3,4,5,6]";
    ListNode* head = stringToListNode(line);
    prettyPrintLinkedList(head);
    int n = 2;

    Solution so;
    auto ans = so.removeNthFromEnd(head, n);
    prettyPrintLinkedList(ans);
    
    return 0;
}