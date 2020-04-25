/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode-cn.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (40.98%)
 * Likes:    473
 * Dislikes: 0
 * Total Accepted:    82.1K
 * Total Submissions: 197.7K
 * Testcase Example:  '[1,2]'
 *
 * 请判断一个链表是否为回文链表。
 * 
 * 示例 1:
 * 
 * 输入: 1->2
 * 输出: false
 * 
 * 示例 2:
 * 
 * 输入: 1->2->2->1
 * 输出: true
 * 
 * 
 * 进阶：
 * 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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
// @lc code=end

