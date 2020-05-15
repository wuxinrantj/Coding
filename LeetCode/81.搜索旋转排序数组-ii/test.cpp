#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() -1;
        
        while (l <= r) {
            while(l!=r && nums[l]==nums[r]) r--;    //比33题多这一行;
            int mid = l + (r - l) / 2;
            if (target == nums[mid]) return true;

            if (nums[l] <= nums[mid])
            {
                if (target >= nums[l] && target < nums[mid])
                    r = mid-1;
                else
                    l = mid+1;
            }
            else
            {
                if (target > nums[mid] && target <= nums[r])
                    l = mid +1;
                else
                    r = mid -1;
            }
        }
        return false;
    }
};

int main(){
    vector<int> nums {2,5,6,0,0,1,2};
    int target = 0;
    Solution so;
    auto ans = so.search(nums, target);
    cout << boolalpha << ans;
    return 0;
}