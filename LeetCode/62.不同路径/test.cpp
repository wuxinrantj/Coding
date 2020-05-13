#include <iostream>
#include <vector>

using namespace std;
//dp[i][j]的值是从起始点走到(i, j)的路径数
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(i == 0 || j == 0) dp[i][j] = 1;
                else dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
            }
        }
        return dp[n - 1][m - 1];
    }
};

int main() {
    int m = 7;
    int n = 3;
    Solution so;
    auto ans = so.uniquePaths(m, n);
    cout << ans ;
    return 0;
}