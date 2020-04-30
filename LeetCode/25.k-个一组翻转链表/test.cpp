#include "../list.h"

using namespace std;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *p = dummy;
        ListNode *cur = p->next;
        ListNode *nxt;
        ListNode *flag = p;
        while(p->next) {
            cur = p->next;
            flag = p;
            for(int i = 0; i < k; ++i) {
                if(flag->next == nullptr) return dummy->next;
                flag = flag->next;
            }
            for(int i = 1; i < k; ++i) {
                nxt = cur->next;
                cur->next = nxt->next;
                nxt->next = p->next;
                p->next = nxt;
            }
            p = cur;
        }

        return dummy->next;
    }
};



int main() {
    string line = "[1,2,3,4,5]";
    int k = 2;
    ListNode* head = stringToListNode(line);
    prettyPrintLinkedList(head);

    Solution so;
    auto ans = so.reverseKGroup(head, k);
    prettyPrintLinkedList(ans); 
    
    return 0;
}