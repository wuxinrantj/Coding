#include <iostream>
#include <vector>
#include <string>

using namespace std;

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

int main() {
    vector<vector<char>> board {{'A','B','C','E'},
                                {'S','F','C','S'},
                                {'A','D','E','E'}};
    string word = "SEE";
    Solution so;
    auto ans = so.exist(board, word);
    cout << boolalpha << ans;
    return 0;
}