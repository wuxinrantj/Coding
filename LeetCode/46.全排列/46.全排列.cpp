/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (74.47%)
 * Likes:    625
 * Dislikes: 0
 * Total Accepted:    105.6K
 * Total Submissions: 141.1K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个 没有重复 数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        // 记录走过的路径
        vector<int> track;
        backtrack(nums, track);
        return res;
    }

    void backtrack(vector<int>& nums, vector<int>& track) {
        if(nums.size() == track.size()) {
            res.push_back(track);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            vector<int>::iterator it = find(track.begin(), track.end(), nums[i]); 
            if (it != track.end()) {  //排除在 track 中已经选择过的数字；
                continue;
            }
            
            track.push_back(nums[i]);
            backtrack(nums, track);
            track.pop_back();
        }
    }
};
// @lc code=end

