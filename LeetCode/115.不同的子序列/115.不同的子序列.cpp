/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 *
 * https://leetcode-cn.com/problems/distinct-subsequences/description/
 *
 * algorithms
 * Hard (47.18%)
 * Likes:    184
 * Dislikes: 0
 * Total Accepted:    13K
 * Total Submissions: 27.3K
 * Testcase Example:  '"rabbbit"\n"rabbit"'
 *
 * 给定一个字符串 S 和一个字符串 T，计算在 S 的子序列中 T 出现的个数。
 * 
 * 一个字符串的一个子序列是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE"
 * 的一个子序列，而 "AEC" 不是）
 * 
 * 题目数据保证答案符合 32 位带符号整数范围。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：S = "rabbbit", T = "rabbit"
 * 输出：3
 * 解释：
 * 
 * 如下图所示, 有 3 种可以从 S 中得到 "rabbit" 的方案。
 * (上箭头符号 ^ 表示选取的字母)
 * 
 * rabbbit
 * ^^^^ ^^
 * rabbbit
 * ^^ ^^^^
 * rabbbit
 * ^^^ ^^^
 * 
 * 
 * 示例 2：
 * 
 * 输入：S = "babgbag", T = "bag"
 * 输出：5
 * 解释：
 * 
 * 如下图所示, 有 5 种可以从 S 中得到 "bag" 的方案。 
 * (上箭头符号 ^ 表示选取的字母)
 * 
 * babgbag
 * ^^ ^
 * babgbag
 * ^^    ^
 * babgbag
 * ^    ^^
 * babgbag
 * ⁠ ^  ^^
 * babgbag
 * ⁠   ^^^
 * 
 */

// @lc code=start
// dp[i][j] s的前j个和t的前i个字符串的不同子序列
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<long long>> dp(t.size() + 1, vector<long long>(s.size() + 1,0));

        for(int i = 0; i < t.size(); ++i) {
            for(int j = 0; j < s.size(); ++j) {
                if(i == 0) dp[i][j] = 1;
                if (t[i] == s[j]) dp[i+1][j+1] = dp[i+1][j] + dp[i][j];  // 左边和左上
                else dp[i+1][j+1] = dp[i+1][j];
            }
        }
        return dp[t.size()][s.size()];
    }
};
// @lc code=end

