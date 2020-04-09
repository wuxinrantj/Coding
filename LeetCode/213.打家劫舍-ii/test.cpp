
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        } else {
            return max(robrange(nums, 0, nums.size()-2), robrange(nums, 1, nums.size()-1));//首尾只能一个被抢，且去除首尾同时被抢
        }
    }

    // 仅计算闭区间 [start,end] 的最优结果
    int robrange(vector<int>& nums, int start, int end) {
        int dp_i_1 = 0; int dp_i_2 = 0;
        int dp_i = 0;
        for(int i = end; i >= start; --i) {
            dp_i = max(dp_i_1, dp_i_2 + nums[i]);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        return dp_i;
    }
};


int main(void)
{
    vector<int> nums{2,3,2};

    Solution so;
    auto ans = so.rob(nums);
    cout << ans << endl;

    return 0;
}
