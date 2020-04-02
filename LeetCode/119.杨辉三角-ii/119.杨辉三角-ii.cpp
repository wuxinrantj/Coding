/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode-cn.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (60.39%)
 * Likes:    132
 * Dislikes: 0
 * Total Accepted:    45.6K
 * Total Submissions: 75.2K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: [1,3,3,1]
 * 
 * 
 * 进阶：
 * 
 * 你可以优化你的算法到 O(k) 空间复杂度吗？
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {

        vector<int> res(rowIndex + 1, 1);
        for(int i = 0; i <= rowIndex; ++i) {
            for(int j = i; j > 1; --j) {
                res[j - 1] = res[j - 2] + res[j - 1];
            }
        }
        return res;
        
    }
};
// @lc code=end

