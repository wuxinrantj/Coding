/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode-cn.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (35.60%)
 * Likes:    430
 * Dislikes: 0
 * Total Accepted:    34.2K
 * Total Submissions: 95.9K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。
 * 
 * 示例：
 * 
 * 输入: S = "ADOBECODEBANC", T = "ABC"
 * 输出: "BANC"
 * 
 * 说明：
 * 
 * 
 * 如果 S 中不存这样的子串，则返回空字符串 ""。
 * 如果 S 中存在这样的子串，我们保证它是唯一的答案。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        int start = 0, minLen = INT_MAX;
        int left = 0, right = 0;
        unordered_map<char, int> window;
        unordered_map<char, int> needs;
        for (char c : t) needs[c]++;   

        int match = 0;   //匹配的字符个数
        while (right < s.size()) {
            char c1 = s[right];
            if (needs.count(c1)) {
                window[c1]++;
                if (window[c1] == needs[c1])
                match++;
            }
            right++;   //窗口先全包含
            while (match == needs.size()) {
                if (right - left < minLen) {
                    // 更新最⼩⼦串的位置和⻓度
                    start = left;
                    minLen = right - left;
                }
                char c2 = s[left];
                if (needs.count(c2)) {
                    window[c2]--;
                    if (window[c2] < needs[c2])
                    match--;
                }
                left++;   //再缩小窗口大小直到不再全包含
            }
        }
        return minLen == INT_MAX ?
        "" : s.substr(start, minLen);
    }
};
// @lc code=end

