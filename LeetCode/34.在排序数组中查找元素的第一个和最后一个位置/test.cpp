#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        if(nums.size() < 1 || target < nums[0] || target > nums[nums.size() - 1]) return res;
        // 第一次二分查找，找到左边界
        int l = 0, r = nums.size();
        while(l < r){
            int mid = l + (r - l) / 2;
            nums[mid] < target ? l = mid + 1 : r = mid;
        }
        if(target == nums[l]) res[0] = l;
        else return res;
        
        // 第二次二分查找，找到右边界
        r = nums.size();
        while(l < r){
            int mid = l + (r - l) / 2;
            target < nums[mid] ? r = mid : l = mid + 1;
        }
        res[1] = l - 1;
        return res;
    }
};

int main() {
    vector<int> nums{5,7,7,8,8,10};
    int target = 8;

    Solution so;
    auto ans = so.searchRange(nums, target);
    for(int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ',';
    }
    return 0;
}