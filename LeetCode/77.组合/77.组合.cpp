/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (73.19%)
 * Likes:    253
 * Dislikes: 0
 * Total Accepted:    45.9K
 * Total Submissions: 62.4K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 
 * 示例:
 * 
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        if(k <= 0 || n <= 0) {
            return res;
        }
        vector<int> track;
        backtrack(n, k, 1, track);
        return res;
    }

    void backtrack(int n, int k, int start, vector<int>& track) {  //k 限制了树的高度，n 限制了树的宽度
        // 到达树的底部
        if (k == track.size()) {
            res.push_back(track);
            return;
        }
        for (int i = start; i <= n; i++) {
            // 做选择
            track.push_back(i);
            // 回溯
            backtrack(n, k, i + 1, track);
            // 撤销选择
            track.pop_back();
        }
    }
};
// @lc code=end

