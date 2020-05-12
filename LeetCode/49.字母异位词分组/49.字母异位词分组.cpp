/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode-cn.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (61.17%)
 * Likes:    335
 * Dislikes: 0
 * Total Accepted:    71.9K
 * Total Submissions: 117.1K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
 * 
 * 示例:
 * 
 * 输入: ["eat", "tea", "tan", "ate", "nat", "bat"]
 * 输出:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * 说明：
 * 
 * 
 * 所有输入均为小写字母。
 * 不考虑答案输出的顺序。
 * 
 * 
 */

// @lc code=start
//引入一个hash表，索引是排序后的单词，值为结果vector的下标
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;  
        int count = 0;
        string tmp;
        unordered_map<string, int> work;
        for(auto str:strs)
        {
            tmp = str;
            sort(tmp.begin(),tmp.end());
            if(work.count(tmp)) {
                res[work[tmp]].push_back(str);
            } else {
                vector<string> vec(1, str);
                res.push_back(vec);
                work[tmp] = count ++;
            }
        }
        return res;
    }
};
// @lc code=end

