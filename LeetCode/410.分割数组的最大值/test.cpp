#include <iostream>
#include <vector>

using namespace std;
//二分   在max(nums)和sum(nums)之间
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        auto l = nums[0];
        long long r = 0;
        for(auto i : nums) {
            r += i;
            l = l > i ? l : i;
        }
        while(l < r) {
            long long mid = l + (r - l) / 2;
            long long temp = 0;
            auto cnt = 1;
            for(auto i : nums){
                temp += i;
                if(temp > mid) {
                    temp = i;
                    ++cnt;
                }
            }
            if(cnt > m) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};

int main() {
    vector<int> nums{1,2147483647};
    int m = 2;
    Solution so;
    auto ans = so.splitArray(nums, m);
    cout << ans << endl;
    return 0; 
}