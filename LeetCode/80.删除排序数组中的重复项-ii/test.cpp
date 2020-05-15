#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();
        int slow = 1;
        for(int fast = 2; fast < nums.size(); ++fast)
        {
            if(nums[fast] != nums[slow - 1]) {
                nums[++slow] = nums[fast];
            }
        }
        return ++slow;
    }
};

int main() {
    vector<int> nums{0,0,1,1,1,1,2,3,3};
    Solution so;
    auto ans = so.removeDuplicates(nums);
    cout << ans ;
    return 0;
}