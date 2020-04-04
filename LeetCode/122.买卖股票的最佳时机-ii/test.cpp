
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        for(int i = 1; i < prices.size(); ++i) {
            if(prices[i] - prices[i-1] > 0) {
                profit += max(0, prices[i] - prices[i-1]);
            } 
        }

        return profit;
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
