#include <iostream>
#include <vector>
#include <string>

using namespace std;
//dfs+位运算
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


int main() {
    int n = 8;
    Solution so;
    auto ans = so.totalNQueens(n);
    cout << ans << endl;
    return 0;
}