/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (39.22%)
 * Likes:    411
 * Dislikes: 0
 * Total Accepted:    87.2K
 * Total Submissions: 221K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 如果数组中不存在目标值，返回 [-1, -1]。
 * 
 * 示例 1:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 8
 * 输出: [3,4]
 * 
 * 示例 2:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 6
 * 输出: [-1,-1]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        if(nums.size() < 1 || target < nums[0] || target > nums[nums.size() - 1]) return res;
        // 第一次二分查找，找到左边界
        int l = 0, r = nums.size();
        while(l < r){
            int mid = l + (r - l) / 2;
            nums[mid] < target ? l = mid + 1 : r = mid;
        }
        if(target == nums[l]) res[0] = l;
        else return res;
        
        // 第二次二分查找，找到右边界
        r = nums.size();
        while(l < r){
            int mid = l + (r - l) / 2;
            target < nums[mid] ? r = mid : l = mid + 1;
        }
        res[1] = l - 1;
        return res;
    }
};
// @lc code=end

