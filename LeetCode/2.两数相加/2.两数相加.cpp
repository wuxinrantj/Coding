/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (36.91%)
 * Likes:    4202
 * Dislikes: 0
 * Total Accepted:    392.2K
 * Total Submissions: 1.1M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 * 
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 示例：
 * 
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
// @lc code=end

