
#include <iostream>
#include <vector>

using namespace std;
// dp[i] = x 表⽰：
// 从第 i 间房⼦开始抢劫，最多能抢到的钱为 x
class Solution {
public:
    int rob(vector<int>& nums) {
        int dp_i_1 = 0; int dp_i_2 = 0;
        int dp_i = 0;
        for(int i = nums.size() - 1; i >= 0; --i) {
            dp_i = max(dp_i_1, dp_i_2 + nums[i]);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        return dp_i;
    }
};


int main(void)
{
    vector<int> nums{2,7,9,3,1};

    Solution so;
    auto ans = so.rob(nums);
    cout << ans << endl;

    return 0;
}
