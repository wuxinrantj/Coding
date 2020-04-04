
#include <iostream>
#include <vector>

using namespace std;
//前i天的最大收益 = max{前i-1天的最大收益，第i天的价格-前i-1天中的最小价格}
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minprice = INT_MAX;

        for(int i = 0; i < prices.size(); ++i) {
            profit = max(profit, prices[i] - minprice);
            minprice = min(minprice, prices[i]);
        }

        return profit;
    }
};


int main(void)
{
    vector<int> nums{7,6,4,3,1};

    int ans;
    Solution so;
    ans = so.maxProfit(nums);
    cout << ans << endl;

    return 0;
}
