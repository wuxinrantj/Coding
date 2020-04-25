#include <iostream>
#include <vector>

using namespace std;
// 0-n求和 减去当前和  
// 避免数组越界  边求和边减
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        res += n - 0;
        for(int i = 0; i < n; ++i) {
            res += i - nums[i];
        }
        return res;
    }
};

int main() {
    vector<int> nums{9,6,4,2,3,5,7,0,1};
    Solution so;
    auto ans = so.missingNumber(nums);
    cout << ans << endl;
    return 0;
}