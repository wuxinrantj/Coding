/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 *
 * https://leetcode-cn.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (32.57%)
 * Likes:    276
 * Dislikes: 0
 * Total Accepted:    57.5K
 * Total Submissions: 174.7K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 * 
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 * 
 * 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
 * 
 * 
 * 
 * 网格中的障碍物和空位置分别用 1 和 0 来表示。
 * 
 * 说明：m 和 n 的值均不超过 100。
 * 
 * 示例 1:
 * 
 * 输入:
 * [
 * [0,0,0],
 * [0,1,0],
 * [0,0,0]
 * ]
 * 输出: 2
 * 解释:
 * 3x3 网格的正中间有一个障碍物。
 * 从左上角到右下角一共有 2 条不同的路径：
 * 1. 向右 -> 向右 -> 向下 -> 向下
 * 2. 向下 -> 向下 -> 向右 -> 向右
 * 
 * 
 */

// @lc code=start
//障碍物直接置零
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = !obstacleGrid[0][0];
        for(int i = 1; i < n; i++) dp[i][0] = (obstacleGrid[i][0] || dp[i-1][0] == 0) ? 0 : 1;
        for(int j = 1; j < m; j++) dp[0][j] = (obstacleGrid[0][j] || dp[0][j-1] == 0) ? 0 : 1;
        for(int i = 1; i < n; i++)
            for(int j = 1; j < m; j++)
                dp[i][j] = obstacleGrid[i][j] ? 0 : dp[i-1][j]+dp[i][j-1];
        return dp[n - 1][m - 1];
    }
};
// @lc code=end

