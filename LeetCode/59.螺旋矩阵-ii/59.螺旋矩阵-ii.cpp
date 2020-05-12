/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 *
 * https://leetcode-cn.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (76.83%)
 * Likes:    180
 * Dislikes: 0
 * Total Accepted:    33.6K
 * Total Submissions: 43.4K
 * Testcase Example:  '3'
 *
 * 给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 1));
        int u = 0;
        int d = n - 1;
        int l = 0;
        int r = n - 1;
        int count = 1;
        while(true) {
            for(int i = l; i <= r; ++i) res[u][i] = count++;
            if(++u > d) break;
            for(int i = u; i <= d; ++i) res[i][r] = count++;
            if(--r < l) break;
            for(int i = r; i >= l; --i) res[d][i] = count++;
            if(--d < u) break;
            for(int i = d; i >= u; --i) res[i][l] = count++;
            if(++l > r) break;
        }
        return res;
    }
};
// @lc code=end

