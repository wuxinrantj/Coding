
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
        vector<vector<int> > dp(kmax + 1, vector<int>{0, INT_MIN}); // 三维DP化简二维
        for (int i = 0; i < prices.size(); ++i) 
        {
            for (int j = kmax; j > 0; --j) 
            {
                dp[j][0] = max(dp[j][0], dp[j][1] + prices[i]);
                dp[j][1] = max(dp[j][1], dp[j - 1][0] - prices[i]);
            }
        }
        return dp[kmax][0];

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
