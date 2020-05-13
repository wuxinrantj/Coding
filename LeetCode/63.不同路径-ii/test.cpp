#include <iostream>
#include <vector>

using namespace std;
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

int main() {
    vector<vector<int>> obstacleGrid{
                                    {0,0,0},
                                    {0,1,0},
                                    {0,0,0}
                                    };
    Solution so;
    auto ans = so.uniquePathsWithObstacles(obstacleGrid);
    cout << ans ;
    return 0;
}