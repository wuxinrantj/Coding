/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 *
 * https://leetcode-cn.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (29.02%)
 * Likes:    1967
 * Dislikes: 0
 * Total Accepted:    226.4K
 * Total Submissions: 774.2K
 * Testcase Example:  '"babad"'
 *
 * 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 * 
 * 示例 1：
 * 
 * 输入: "babad"
 * 输出: "bab"
 * 注意: "aba" 也是一个有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入: "cbbd"
 * 输出: "bb"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2) {
            return s;
        }
        int maxlen = 1;
        int start = 0;
		string str = "";
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

        for(int j = 1; j < s.size(); ++j) {
            for(int i = 0; i <= j; ++i) {
                if(s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1] == true)) {
                    dp[i][j] = true;
                    if(j - i + 1 > maxlen)
                    {
                        maxlen = j - i + 1;
                        start = i;
                    }
                }
                else
                    dp[i][j] = false;
            }
        }
        return s.substr(start, maxlen);

    }
};
// @lc code=end

