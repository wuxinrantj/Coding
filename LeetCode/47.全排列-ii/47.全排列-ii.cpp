/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (57.64%)
 * Likes:    287
 * Dislikes: 0
 * Total Accepted:    56.8K
 * Total Submissions: 97.1K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列，返回所有不重复的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,1,2]
 * 输出:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 */

// @lc code=start
//回溯
class Solution {
public:
    vector<vector<int>> res;
    vector<bool> marked; 
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // 记录走过的路径
        vector<int> track;
        marked = vector<bool>(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, track);
        return res;
    }

    void backtrack(vector<int>& nums, int start, vector<int>& track) {
        if(nums.size() == start) {
            res.push_back(track);
            return;
        }
        
        for(int i = 0; i < nums.size(); ++i){
            if(marked[i])
                continue;

            if(i > 0 && nums[i] == nums[i-1] && marked[i-1] == false) {
                continue;
            }
            track.push_back(nums[i]);
            marked[i] = true;
            backtrack(nums, start + 1, track);
            track.pop_back();
            marked[i] = false;
        }
        return;
    }
};
// @lc code=end

