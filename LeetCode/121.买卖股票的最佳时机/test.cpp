
#include <iostream>
#include <vector>

using namespace std;
//最大子序和
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dp = 0;
        int res = 0;

        for(int i = 1; i < prices.size(); ++i) {
            if(dp > 0) {
                dp += prices[i] - prices[i-1];
            } else {
                dp = prices[i] - prices[i - 1];
            }
            res = max(dp, res);
        }

        return res;
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
