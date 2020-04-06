
#include <iostream>
#include <vector>

using namespace std;
//DP
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
        {
            return 0;
        }
        int kmax = 2;
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(kmax + 1, vector<int>(2,0)));

        for(int i = 0; i < prices.size(); ++i) {
            for(int k = kmax; k >= 1; --k) {
                if(i == 0) {
                    dp[i][k][0] = 0;
                    dp[i][k][1] = - prices[i];   //// dp[i][1]
                                                    // = max(dp[-1][1], dp[-1][0] - prices[i])
                                                    // = max(-infinity, 0 - prices[i])
                                                    // = -prices[i]
                    continue;
                }

                dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
                dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
            }
        }

        return dp[prices.size() - 1][kmax][0];
    }
};


int main(void)
{
    vector<int> nums{1,2,3,4,5};

    int ans;
    Solution so;
    ans = so.maxProfit(nums);
    cout << ans << endl;

    return 0;
}
