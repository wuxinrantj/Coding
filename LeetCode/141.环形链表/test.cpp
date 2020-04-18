#include "../list.h"

using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast{head};
        ListNode* slow{head};

        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                return true;
            }
        }
        return false;
    }
};


int main() {
    string line = "[1,2,3,4,5]";
    ListNode* head = stringToListNode(line);
    prettyPrintLinkedList(head);

    Solution so;
    auto ans = so.reverseList(head);
    cout << boolalpha << ans << endl;
    
    return 0;
}