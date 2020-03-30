
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int dp = 0;
        int res = nums[0];

        for(int i = 0; i < nums.size(); ++i) {
            if(dp < 0) {
                dp = nums[i];
            } else {
                dp += nums[i];
            }
            res = max(dp, res);
        }

        return res;
    }
};

int main(void)
{
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};

    int ans;
    Solution so;
    ans = so.maxSubArray(nums);
    cout << ans << endl;

    return 0;
}
