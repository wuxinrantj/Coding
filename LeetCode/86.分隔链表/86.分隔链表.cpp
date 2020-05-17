/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 *
 * https://leetcode-cn.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (56.56%)
 * Likes:    193
 * Dislikes: 0
 * Total Accepted:    36.2K
 * Total Submissions: 62.8K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
 * 
 * 你应当保留两个分区中每个节点的初始相对位置。
 * 
 * 示例:
 * 
 * 输入: head = 1->4->3->2->5->2, x = 3
 * 输出: 1->2->2->4->3->5
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
// @lc code=end

