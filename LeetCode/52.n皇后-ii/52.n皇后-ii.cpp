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
    vector<vector<string>> res;
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);
        return res.size();
    }

    void backtrack(vector<string>& board, int row) {
        if (row == board.size()) {
            res.push_back(board);
            return;
        }
        int n = board[row].size();
        for (int col = 0; col < n; col++) {
            // 排除不合法选择
            if (!isValid(board, row, col)) {
                continue;
            }
            // 做选择
            board[row][col] = 'Q';
            // 进⼊下⼀⾏决策
            backtrack(board, row + 1);
            // 撤销选择
            board[row][col] = '.';
        }
    }

    bool isValid(vector<string>& board, int row, int col) {
        int n = board.size();
        // 检查列是否有皇后互相冲突
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q')
            return false;
        }
        // 检查右上⽅是否有皇后互相冲突
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
            return false;
        }
        // 检查左上⽅是否有皇后互相冲突
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
            return false;
        }
        return true;
    }
};
// @lc code=end

