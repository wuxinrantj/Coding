/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 *
 * https://leetcode-cn.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (39.27%)
 * Likes:    588
 * Dislikes: 0
 * Total Accepted:    46.5K
 * Total Submissions: 118K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 * 
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 * 
 * 
 * 
 * 
 * 
 * 以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。
 * 
 * 
 * 
 * 
 * 
 * 图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: [2,1,5,6,2,3]
 * 输出: 10
 * 
 */

// @lc code=start
//单调栈
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    int res = 0;
    vector<int> stack;
    heights.insert(heights.begin(), 0);
    heights.push_back(0);
    for (int i = 0; i < heights.size(); i++) {
        while (!stack.empty() && heights[stack.back()] > heights[i]) {
            int cur = stack.back();
            stack.pop_back();
            int left = stack.back() + 1;
            int right = i - 1;
            res = max(res, (right - left + 1) * heights[cur]);
        }
        stack.push_back(i);
    }
    return res;
    }
};
// @lc code=end

