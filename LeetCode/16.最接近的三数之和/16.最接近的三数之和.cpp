/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 *
 * https://leetcode-cn.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (43.40%)
 * Likes:    410
 * Dislikes: 0
 * Total Accepted:    95.5K
 * Total Submissions: 217.9K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
 * 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 * 
 * 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
 * 
 * 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int cha = INT_MAX;
        int res;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len - 2; i++){
            int p1 = i + 1, p2 = len - 1; 
            while(p1 < p2){
                if(nums[p1] + nums[p2] + nums[i] < target){
                    if(cha > min(cha, abs(target - nums[i] - nums[p1] - nums[p2]))) {
                        cha = min(cha, abs(target - nums[i] - nums[p1] - nums[p2]));
                        res = nums[p1] + nums[p2] + nums[i];
                    }
                    p1 ++;
                } else if (nums[p1] + nums[p2] + nums[i] == target){
                    return nums[p1] + nums[p2] + nums[i];
                } else {
                    if(cha > min(cha, abs(target - nums[i] - nums[p1] - nums[p2]))) {
                        cha = min(cha, abs(target - nums[i] - nums[p1] - nums[p2]));
                        res = nums[p1] + nums[p2] + nums[i];
                    }
                    p2--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

