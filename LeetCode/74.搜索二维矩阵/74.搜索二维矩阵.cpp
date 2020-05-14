/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 *
 * https://leetcode-cn.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (37.63%)
 * Likes:    174
 * Dislikes: 0
 * Total Accepted:    42.9K
 * Total Submissions: 113.4K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * 编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
 * 
 * 
 * 每行中的整数从左到右按升序排列。
 * 每行的第一个整数大于前一行的最后一个整数。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 3
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 13
 * 输出: false
 * 
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0 || target < matrix[0][0]) return false;
        int up = 0;
        int down = matrix.size();
        int rowmid;
        int left = 0;
        int right = matrix[0].size();

        while(up < down) {
            rowmid = up + (down - up) / 2;
            if(matrix[rowmid][0] == target) {
                return true;
            } else if(matrix[rowmid][0] < target) {
                up = rowmid + 1;
            } else {
                down = rowmid;
            }
        }

        while(left < right) {
            int colmid = left + (right - left) / 2;
            if(matrix[up - 1][colmid] == target) {
                return true;
            } else if(matrix[up - 1][colmid] < target) {
                left = colmid + 1;
            } else {
                right = colmid;
            }
        }

        return false;
    }
};
// @lc code=end

