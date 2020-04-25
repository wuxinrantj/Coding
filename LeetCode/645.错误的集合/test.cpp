#include <iostream>
#include<vector>

using namespace std;
// 出现过的数字变成负数
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int repeat = -1;
        for (int i = 0; i < n; ++i) {
            int index = abs(nums[i]) - 1; //从~1~开始
            if (nums[index] < 0)
                repeat = abs(nums[i]);
            else
                nums[index] *= -1;
        }

        int missing = -1;
        for (int i = 0; i < n; i++)
            if (nums[i] > 0)
                missing = i + 1;

        return {repeat, missing};
    }
};

int main() {
    vector<int> nums{1,2,2,4};
    Solution so;
    auto ans = so.findErrorNums(nums);
    for(int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ',' ;
    }
    return 0;
}