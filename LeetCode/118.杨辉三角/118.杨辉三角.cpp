/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (66.01%)
 * Likes:    272
 * Dislikes: 0
 * Total Accepted:    68.7K
 * Total Submissions: 104.1K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 5
 * 输出:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> res(numRows);

        for(int i = 0; i < numRows; ++i) {
            res[i] = vector<int>(i + 1, 0);
            res[i][0] = 1;
            res[i][i] = 1;
        }
        for(int i = 2; i < numRows; ++i){
            for(int j = 1; j < res[i].size() - 1; ++j) {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }

        return res;
    }
};

// @lc code=end

