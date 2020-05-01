/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 *
 * https://leetcode-cn.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (32.99%)
 * Likes:    471
 * Dislikes: 0
 * Total Accepted:    57.9K
 * Total Submissions: 174.2K
 * Testcase Example:  '[1,2,3]'
 *
 * 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
 * 
 * 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
 * 
 * 必须原地修改，只允许使用额外常数空间。
 * 
 * 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return;
        int pos = nums.size() - 1;
        while(pos > 0) {
            if(nums[pos] > nums[pos - 1]) {
                break;
            }
            --pos;
        }
        reverse(nums.begin() + pos, nums.end());  //逆序
		if(pos > 0){
			auto iter = upper_bound(nums.begin() + pos, nums.end(), nums[pos - 1]);//使用upper_bound找到遍历过的数中第一个比num[pos-1]大的数
			swap(*iter, nums[pos - 1]);
		}
    }
};
// @lc code=end

