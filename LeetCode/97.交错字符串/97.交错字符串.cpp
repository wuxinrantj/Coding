/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 *
 * https://leetcode-cn.com/problems/interleaving-string/description/
 *
 * algorithms
 * Hard (39.19%)
 * Likes:    167
 * Dislikes: 0
 * Total Accepted:    13.5K
 * Total Submissions: 33.8K
 * Testcase Example:  '"aabcc"\n"dbbca"\n"aadbbcbcac"'
 *
 * 给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。
 * 
 * 示例 1:
 * 
 * 输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * 输出: false
 * 
 */

// @lc code=start
// dp[i][j] 表示用 s1 的前 (i) 和 s2 的前 (j) 个字符
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int N1 = s1.size();
        int N2 = s2.size();
        int N3 = s3.size();
        if (N1 + N2 != N3) return false;
        vector<vector<bool>> dp(N1 + 1, vector<bool>(N2 + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= N1; ++i) {
            for (int j = 0; j <= N2; ++j) {
                if (i > 0 && s1[i - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
                if (j > 0 && s2[j - 1] == s3[i + j - 1]) {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }
        return dp[N1][N2];
    }
};
// @lc code=end

