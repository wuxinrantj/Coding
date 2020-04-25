#include <iostream>
#include <vector>

using namespace std;
//贪心
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int end = 0, farthest = 0;
        int jumps = 0;
        for (int i = 0; i < n - 1; i++) {
            farthest = max(nums[i] + i, farthest);      //最远的区域可以涵盖前面的
            if (end == i) {
                jumps++;
                end = farthest;
            }
        }
        return jumps;
    }
};

int main() {
    vector<int> nums{2,3,1,1,4};
    Solution so;
    auto ans = so.jump(nums);
    cout << ans << endl;
    return 0;
}