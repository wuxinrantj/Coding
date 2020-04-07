/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 *
 * https://leetcode-cn.com/problems/longest-palindromic-subsequence/description/
 *
 * algorithms
 * Medium (51.52%)
 * Likes:    174
 * Dislikes: 0
 * Total Accepted:    15.8K
 * Total Submissions: 30.3K
 * Testcase Example:  '"bbbab"'
 *
 * 给定一个字符串s，找到其中最长的回文子序列。可以假设s的最大长度为1000。
 * 
 * 示例 1:
 * 输入:
 * 
 * 
 * "bbbab"
 * 
 * 
 * 输出:
 * 
 * 
 * 4
 * 
 * 
 * 一个可能的最长回文子序列为 "bbbb"。
 * 
 * 示例 2:
 * 输入:
 * 
 * 
 * "cbbd"
 * 
 * 
 * 输出:
 * 
 * 
 * 2
 * 
 * 
 * 一个可能的最长回文子序列为 "bb"。
 * 
 */

// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for(int i = 0; i < s.size(); ++i) {      //base case
            dp[i][i] = 1;
        }

        for(int i = s.size() - 1; i >= 0; --i) {    //反向遍历
            for(int j = i + 1; j < s.size(); ++j) {
                if(s[i] == s[j]) {    // 它俩⼀定在最⻓回⽂⼦序列中
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {   // s[i+1..j] 和 s[i..j-1] 谁的回⽂⼦序列更⻓？
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][s.size() - 1];

    }
};
// @lc code=end

