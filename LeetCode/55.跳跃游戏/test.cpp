#include <iostream>
#include <vector>

using namespace std;
//贪心
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;
        for (int i = 0; i < n - 1; ++i) {
            farthest = max(farthest, i + nums[i]);  // 能跳的最远的距离
            if (farthest <= i) return false;
        }
        return farthest >= n - 1;
    }
};

int main() {
    vector<int> nums{2,3,1,1,4};
    Solution so;
    auto ans = so.canJump(nums);
    cout << boolalpha << ans << endl;
    return 0;
}