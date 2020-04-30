/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 *
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (57.06%)
 * Likes:    458
 * Dislikes: 0
 * Total Accepted:    53K
 * Total Submissions: 91K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 * 
 * k 是一个正整数，它的值小于或等于链表的长度。
 * 
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 
 * 
 * 
 * 示例：
 * 
 * 给你这个链表：1->2->3->4->5
 * 
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 * 
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 * 
 * 
 * 
 * 说明：
 * 
 * 
 * 你的算法只能使用常数的额外空间。
 * 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
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
// @lc code=end

