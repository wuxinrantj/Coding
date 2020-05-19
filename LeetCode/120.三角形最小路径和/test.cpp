#include <iostream>
#include <vector>

using namespace std;
// dp 自底向上
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle);
        
        for(int i = triangle.size() - 2; i >=0 ;i--) {
            for(int j = 0; j < triangle[i].size(); j++) {
                dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j];
            }
        }
        return dp[0][0];
    }
};

int main() {
    vector<vector<int>> triangle {{2},
                                 {3,4},
                                {6,5,7},
                               {4,1,8,3}};
    Solution so;
    auto ans = so.minimumTotal(triangle);
    cout << ans;
    return 0;
}