/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 *
 * https://leetcode-cn.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (77.56%)
 * Likes:    111
 * Dislikes: 0
 * Total Accepted:    20.6K
 * Total Submissions: 26.3K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回 n 皇后不同的解决方案的数量。
 * 
 * 示例:
 * 
 * 输入: 4
 * 输出: 2
 * 解释: 4 皇后问题存在如下两个不同的解法。
 * [
 * [".Q..",  // 解法 1
 * "...Q",
 * "Q...",
 * "..Q."],
 * 
 * ["..Q.",  // 解法 2
 * "Q...",
 * "...Q",
 * ".Q.."]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int totalNQueens(int n) {
        dfs(n, 0, 0, 0, 0);
        
        return this->res;
    }
    
    void dfs(int n, int row, int col, int ld, int rd) {
        if (row >= n) { res++; return; }
        
        // 将所有能放置 Q 的位置由 0 变成 1，以便进行后续的位遍历   1 代表不能放置，0 代表可以放置
        int bits = ~(col | ld | rd) & ((1 << n) - 1);      //列、左斜下、右斜下
        while (bits > 0) {
            int pick = bits & -bits; //  x & -x 代表除最后一位 1 保留，其它位全部为 0
            dfs(n, row + 1, col | pick, (ld | pick) << 1, (rd | pick) >> 1);
            bits &= bits - 1; //  x & (x - 1)  代表将最后一位 1 变成 0
        }
    }

private:
    int res = 0;
};
// @lc code=end

