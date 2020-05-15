/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (40.97%)
 * Likes:    404
 * Dislikes: 0
 * Total Accepted:    57.5K
 * Total Submissions: 138.6K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 
 * 
 * 示例:
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * 给定 word = "ABCCED", 返回 true
 * 给定 word = "SEE", 返回 true
 * 给定 word = "ABCB", 返回 false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * board 和 word 中只包含大写和小写英文字母。
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool backtracking(vector<vector<char>>& board, string& word, int i,int j, int w){
        if(board[i][j] != word[w]) return false;
        if(w == word.size() - 1) return true;
        char tmp = board[i][j]; board[i][j] = 0;
        if( (i - 1 >= 0 && backtracking(board, word, i-1, j, w+1))                   //向上
         || (j + 1 <= board[0].size()-1 && backtracking(board, word, i, j+1, w+1))   //向右
         || (i + 1 <= board.size() - 1 && backtracking(board, word, i+1, j, w+1))    //向下
         || (j - 1 >= 0 && backtracking(board, word, i, j-1, w+1)) ) return true;    //向左
        board[i][j] = tmp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j)
                if(backtracking(board, word, i, j, 0)) return true;
        }
        return false;
    }
};
// @lc code=end

