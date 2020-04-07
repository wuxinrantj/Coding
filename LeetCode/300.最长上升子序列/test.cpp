
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(empty(nums)) {
            return 0;
        }
        vector<int> dp(nums.size(), 1);
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};

int main(void)
{
    vector<int> nums{10,9,2,5,3,7,101,18};

    int ans;
    Solution so;
    ans = so.lengthOfLIS(nums);
    cout << ans << endl;

    return 0;
}
