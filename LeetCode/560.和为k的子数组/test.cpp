#include <iostream>
#include <vector>

using namespace std;
//前缀和
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> presum(nums.size() + 1, 0);
        int count = 0;

        for(int i = 0; i < nums.size(); i++) {
            presum[i + 1] = presum[i] + nums[i];
        }

        for(int i = 1; i <= nums.size(); ++i) {
            for(int j = 0; j < i; ++j) {
                if(presum[i] - presum[j] == k){
                    count++;
                }
            }
        }

        return count;
    }
};

int main() {
    vector<int> nums{1,1,1};
    int k = 2;
    Solution so;
    auto ans = so.subarraySum(nums, k);
    cout << ans << endl;
    return 0;
}