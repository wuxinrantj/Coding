/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (52.90%)
 * Likes:    686
 * Dislikes: 0
 * Total Accepted:    106.2K
 * Total Submissions: 199.4K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */

// @lc code=start
class Solution {
public:
    map<char, string> phone{ {'1', ""},
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
        {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    string temp;
    vector<string> res;

    void backtrack(int index, string digits) {
        if(index == digits.size()) {
            res.push_back(temp);
            return;
        }

        for(int i = 0; i < phone[digits[index]].size(); i++) {
            temp.push_back(phone[digits[index]][i]);
            backtrack(index + 1, digits);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) {
            return res;
        }
        backtrack(0, digits);

        return res;
    }
};
// @lc code=end

