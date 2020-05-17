#include "../list.h"

using namespace std;

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head)
            return head;

        ListNode *small = new ListNode(-1);
        ListNode *big = new ListNode(-1);
        ListNode *p1 = small, *p2 = big;

        while(head) {
            if(head->val < x) {
                p1->next = head;
                p1 = p1->next;
                head = head->next;
            } else {
                p2->next = head;
                p2 = p2->next;
                head = head->next;
            }
        }

        p2->next = NULL;
        p1->next = big->next;
        return small->next;
    }
};

int main() {
    string line = "[1,4,3,2,5,2]";
    int x = 3;
    ListNode* head = stringToListNode(line);
    prettyPrintLinkedList(head);

    Solution so;
    auto ans = so.partition(head, x);
    prettyPrintLinkedList(ans); 
    
    return 0;
}