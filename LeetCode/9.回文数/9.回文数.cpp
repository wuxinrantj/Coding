/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 *
 * https://leetcode-cn.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (57.22%)
 * Likes:    976
 * Dislikes: 0
 * Total Accepted:    280.6K
 * Total Submissions: 490.1K
 * Testcase Example:  '121'
 *
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 * 
 * 示例 1:
 * 
 * 输入: 121
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: -121
 * 输出: false
 * 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 * 
 * 
 * 示例 3:
 * 
 * 输入: 10
 * 输出: false
 * 解释: 从右向左读, 为 01 。因此它不是一个回文数。
 * 
 * 
 * 进阶:
 * 
 * 你能不将整数转为字符串来解决这个问题吗？
 * 
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
        {
            return false;
        }
        if (x < 10)
        {
            return true;
        }

        int i = 0;
        int y = x;
        while (x != 0)
        {
            x /= 10;
            i++;
        }

        while (i > 0)
        {
            if (y % 10 != int (y / pow(10 , (i - 1))))
            {
                return false;
            }
            y = y % int(pow(10 , (i - 1))) / 10;
            i -= 2;
        }
        
        return true;
    }
};
// @lc code=end

