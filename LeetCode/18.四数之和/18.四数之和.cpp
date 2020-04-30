/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (37.37%)
 * Likes:    439
 * Dislikes: 0
 * Total Accepted:    73.8K
 * Total Submissions: 196.8K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 * 
 * 注意：
 * 
 * 答案中不可以包含重复的四元组。
 * 
 * 示例：
 * 
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 * 
 * 满足要求的四元组集合为：
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len - 3; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i + 1; j < len - 2; ++j){
                if(j > i + 1 && nums[j] == nums[j-1]) continue;
                int p1 = j + 1, p2 = len - 1;
                while(p1 < p2){
                    if(nums[i] + nums[j] + nums[p1] + nums[p2] < target){
                        p1++;
                    } else if (nums[i] + nums[j] + nums[p1] + nums[p2] == target){
                        if(p1 == j+1){
                            vector<int> vtemp{nums[i], nums[j], nums[p1], nums[p2]};
                            res.push_back(vtemp);
                            vtemp.clear();
                        }else if(nums[p1] != nums[p1-1]){
                            vector<int> vtemp{nums[i], nums[j], nums[p1], nums[p2]};
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

