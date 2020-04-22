/*
 * @lc app=leetcode.cn id=1034 lang=cpp
 *
 * [1034] 边框着色
 *
 * https://leetcode-cn.com/problems/coloring-a-border/description/
 *
 * algorithms
 * Medium (41.08%)
 * Likes:    9
 * Dislikes: 0
 * Total Accepted:    1.6K
 * Total Submissions: 3.9K
 * Testcase Example:  '[[1,1],[1,2]]\n0\n0\n3'
 *
 * 给出一个二维整数网格 grid，网格中的每个值表示该位置处的网格块的颜色。
 * 
 * 只有当两个网格块的颜色相同，而且在四个方向中任意一个方向上相邻时，它们属于同一连通分量。
 * 
 * 连通分量的边界是指连通分量中的所有与不在分量中的正方形相邻（四个方向上）的所有正方形，或者在网格的边界上（第一行/列或最后一行/列）的所有正方形。
 * 
 * 给出位于 (r0, c0) 的网格块和颜色 color，使用指定颜色 color 为所给网格块的连通分量的边界进行着色，并返回最终的网格 grid
 * 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：grid = [[1,1],[1,2]], r0 = 0, c0 = 0, color = 3
 * 输出：[[3, 3], [3, 2]]
 * 
 * 
 * 示例 2：
 * 
 * 输入：grid = [[1,2,2],[2,3,2]], r0 = 0, c0 = 1, color = 3
 * 输出：[[1, 3, 3], [2, 3, 3]]
 * 
 * 
 * 示例 3：
 * 
 * 输入：grid = [[1,1,1],[1,1,1],[1,1,1]], r0 = 1, c0 = 1, color = 2
 * 输出：[[2, 2, 2], [2, 1, 2], [2, 2, 2]]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= grid.length <= 50
 * 1 <= grid[0].length <= 50
 * 1 <= grid[i][j] <= 1000
 * 0 <= r0 < grid.length
 * 0 <= c0 < grid[0].length
 * 1 <= color <= 1000
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        int origColor = grid[r0][c0];
        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false));
        refill(grid, r0, c0, origColor, color, visited);
        
        return grid;
    }

    int refill(vector<vector<int>>& image, int x, int y, int origColor, int newColor, vector<vector<bool>>& visited) {
        if(x < 0 || x >= image.size() || y < 0 || y >= image[0].size()) {
            return 0;
        }
        if (visited[x][y]) {
            return 1;
        }
        if(image[x][y] != origColor) {
            return 0;
        }
        
        visited[x][y] = true; //打标记，避免重复；
        //区域边界上的坐标，⾄少有⼀个⽅向不是 origColor，⽽区域内部的坐标，四⾯都是 origColor，
        int around = refill(image, x - 1, y, origColor, newColor, visited) + 
                     refill(image, x + 1, y, origColor, newColor, visited) +
                     refill(image, x, y - 1, origColor, newColor, visited) +
                     refill(image, x, y + 1, origColor, newColor, visited);
        if (around < 4) {
            image[x][y] = newColor;
        }

        // image[x][y] == origColor 
        return 1;
    }

};
// @lc code=end

