/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (64.85%)
 * Likes:    481
 * Dislikes: 0
 * Total Accepted:    97.6K
 * Total Submissions: 149.4K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 
 * 
 * 示例:
 * 
 * 给定 1->2->3->4, 你应该返回 2->1->4->3.
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
    ListNode* swapPairs(ListNode* head) {
        if(!head) return nullptr;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *p = dummy;

        while(p->next != nullptr && p->next->next != nullptr) {
            ListNode* firstNode = p->next;
            ListNode* secondNode = firstNode->next;

            p->next = secondNode;
            firstNode->next = secondNode->next;
            secondNode->next = firstNode;
            p = firstNode;
        }
        return dummy->next;
    }
};
// @lc code=end

