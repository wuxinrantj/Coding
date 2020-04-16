/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 *
 * https://leetcode-cn.com/problems/reverse-linked-list-ii/description/
 *
 * algorithms
 * Medium (49.46%)
 * Likes:    343
 * Dislikes: 0
 * Total Accepted:    44.6K
 * Total Submissions: 89.8K
 * Testcase Example:  '[1,2,3,4,5]\n2\n4'
 *
 * 反转从位置 m 到 n 的链表。请使用一趟扫描完成反转。
 * 
 * 说明:
 * 1 ≤ m ≤ n ≤ 链表长度。
 * 
 * 示例:
 * 
 * 输入: 1->2->3->4->5->NULL, m = 2, n = 4
 * 输出: 1->4->3->2->5->NULL
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        //设置哑节点的好处：在m=1时，我们也有前驱节点，也可以将cur的next节点依次插入到pre的后面
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy;
        //找到m的前驱节点
        for(int i = 1; i < m; ++i) pre = pre->next;
        ListNode *cur = pre->next;
        for(int i = m; i < n; ++i) {//每次循环将nxt节点插入到pre的后面
            ListNode *nxt = cur->next;
            //cur将nxt节点后面的链表连接起来
            cur->next = nxt->next;
            //将nxt插入到pre后面
            nxt->next = pre->next;
            pre->next = nxt;
        }
        return dummy->next;
    }
};
// @lc code=end

