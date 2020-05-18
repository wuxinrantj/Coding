#include "../binarytree.h"
#include "../list.h"
// 采用左闭右开区间,tail表示开区间的边界，不用断开链表。
// 递归
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head, nullptr);
    }
    
    TreeNode * buildTree(ListNode* head, ListNode * tail){
        if(head == tail) return nullptr;
        ListNode* slow = head, *fast = head;
        while(fast != tail && fast->next != tail){ // 快慢指针找中点
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode * root = new TreeNode(slow->val);
        root->left = buildTree(head, slow);
        root->right = buildTree(slow->next, tail);
        return root;
    }
};


int main() {
    string line = "[-10, -3, 0, 5, 9]";
    ListNode* head = stringToListNode(line);
    prettyPrintLinkedList(head);

    Solution so;
    auto ans = so.sortedListToBST(head);
    prettyPrintTree(ans);
    
    return 0;
}