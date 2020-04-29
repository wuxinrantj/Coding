#include "../list.h"

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int sum = 0;
        // 无用的头节点
        ListNode* newhead = new ListNode(0);
        ListNode* nownode = newhead;
        // 当l1和l2都为空且无进位时才退出循环
        while(l1 || l2 || carry) {
            // 该结果位的值等于两链表对应位置的值之和再加上上一位的进位
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            // 计算该位的进位
            carry=sum / 10;
            // 该位的值等于sum与10取余
            ListNode* node = new ListNode(sum % 10);
            // 将新节点加入结果链表中
            nownode->next = node;
            nownode = nownode->next;

            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }
        
        return newhead->next;
    }
};

int main() {
    string line1 = "[2,4,3]";
    ListNode* l1 = stringToListNode(line1);
    prettyPrintLinkedList(l1);

    string line2 = "[5,6,4]";
    ListNode* l2 = stringToListNode(line2);
    prettyPrintLinkedList(l2);

    Solution so;
    auto ans = so.addTwoNumbers(l1, l2);
    prettyPrintLinkedList(ans);
    
    return 0;
}