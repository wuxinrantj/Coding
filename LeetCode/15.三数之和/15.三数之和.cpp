/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (26.07%)
 * Likes:    2042
 * Dislikes: 0
 * Total Accepted:    206.5K
 * Total Submissions: 774.6K
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？请你找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例：
 * 
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

// @lc code=start
// 1. 三数和变为两数和  2. 双指针
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len - 2; i++){
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])){  //去重
                int p1 = i + 1, p2 = len - 1; 
                while(p1 < p2){
                    if(nums[p1] + nums[p2] < -nums[i]){
                        p1++;
                    } else if (nums[p1] + nums[p2] == -nums[i]){  //去重
                        if(p1 == i+1){
                            vector<int> vtemp{nums[i], nums[p1], nums[p2]};
                            res.push_back(vtemp);
                            vtemp.clear();
                        }else if(nums[p1] != nums[p1-1]){   //去重
                            vector<int> vtemp{nums[i], nums[p1], nums[p2]};
                            res.push_back(vtemp);
                            vtemp.clear();
                        }
                        p1++,p2--;
                    } else {
                        p2--;
                    }
                }
            }
        }
        return res;

    }
};
// @lc code=end

