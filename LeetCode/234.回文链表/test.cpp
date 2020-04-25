#include "../list.h"
// 后半部分链表反转
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow, *fast;
        slow = fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast != nullptr)
            slow = slow->next;      // slow 指针现在指向链表中点
        
        ListNode *left = head;
        ListNode *right = reverselist(slow);
        while (right != nullptr) {
            if (left->val != right->val)
                return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }

    ListNode* reverselist(ListNode* head) {
        ListNode *pre = nullptr, *cur = head;
        while (cur != nullptr) {
        ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

int main() {
    string line = "[1,2,2,1]";
    ListNode* head = stringToListNode(line);
    prettyPrintLinkedList(head);

    Solution so;
    auto ans = so.isPalindrome(head);
    cout << boolalpha << ans << endl;
    
    return 0;
}