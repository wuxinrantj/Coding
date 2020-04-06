
#include <iostream>
#include <vector>

using namespace std;
//DP
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int dp_i_0 = 0;
        int dp_i_1 = INT_MIN;

        for(int i = 0; i < prices.size(); ++i) {
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
            dp_i_1 = max(dp_i_1, temp - prices[i] - fee);
        }

        return dp_i_0;
    }
};


int main(void)
{
    vector<int> nums{1, 3, 2, 8, 4, 9};
    int fee = 2;

    int ans;
    Solution so;
    ans = so.maxProfit(nums, fee);
    cout << ans << endl;

    return 0;
}
