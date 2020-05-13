#include "../list.h"

using namespace std;

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return 0;
        ListNode* fast{head};
        ListNode* slow{head};
        ListNode* count{head};
        auto cnt = 0;
        while(count != nullptr) {
            cnt++;
            count = count->next;
        }
        k %= cnt;
        if(!k) return head;

        for(int i = 0; i < k; ++i) {
            fast = fast->next;
        }
        while(fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* res;
        res = slow->next;
        fast->next = head;
        slow->next = nullptr;

        return res;
    }
};


int main() {
    string line = "[0,1,2]";
    int k = 3;
    ListNode* head = stringToListNode(line);
    prettyPrintLinkedList(head);

    Solution so;
    auto ans = so.rotateRight(head, k);
    prettyPrintLinkedList(ans);
    
    return 0;
}