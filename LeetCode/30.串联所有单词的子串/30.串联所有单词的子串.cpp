/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 *
 * https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (29.81%)
 * Likes:    255
 * Dislikes: 0
 * Total Accepted:    30.9K
 * Total Submissions: 102.1K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * 给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
 * 
 * 注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：
 * ⁠ s = "barfoothefoobarman",
 * ⁠ words = ["foo","bar"]
 * 输出：[0,9]
 * 解释：
 * 从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
 * 输出的顺序不重要, [9,0] 也是有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入：
 * ⁠ s = "wordgoodgoodgoodbestword",
 * ⁠ words = ["word","good","best","word"]
 * 输出：[]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
    if (words.size() == 0) return {};
    unordered_map<string, int> wordcnt;
    for (auto& w : words)
    {
        wordcnt[w]++;
    }
    int len = words[0].size();

    vector<int> ans;
    for (int i = 0; i < len; i++)
    {
        int left = i;
        int right = left;
        int cnt = 0;

        unordered_map<string, int> window;
        while (left + words.size() * len <= s.size())
        {
            string temp = "";
            while (cnt < words.size())
            {
                temp = s.substr(right, len);
                if (wordcnt.find(temp) == wordcnt.end() || window[temp] >= wordcnt[temp]) break;
                window[temp]++;
                cnt++;
                right += len;
            }

            if (window == wordcnt)
            {
                ans.push_back(left);
            }

            if (wordcnt.find(temp) != wordcnt.end())
            {
                window[s.substr(left, len)]--;
                cnt--;
                left += len;
            }
            else
            {
                right += len;
                left = right;
                cnt = 0;
                window.clear();
            }
        }
    }
    return ans;
    }
};
// @lc code=end

