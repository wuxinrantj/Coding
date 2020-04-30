#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int cha = INT_MAX;
        int res;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len - 2; i++){
            int p1 = i + 1, p2 = len - 1; 
            while(p1 < p2){
                if(nums[p1] + nums[p2] + nums[i] < target){
                    if(cha > min(cha, abs(target - nums[i] - nums[p1] - nums[p2]))) {
                        cha = min(cha, abs(target - nums[i] - nums[p1] - nums[p2]));
                        res = nums[p1] + nums[p2] + nums[i];
                    }
                    p1 ++;
                } else if (nums[p1] + nums[p2] + nums[i] == target){
                    return nums[p1] + nums[p2] + nums[i];
                } else {
                    if(cha > min(cha, abs(target - nums[i] - nums[p1] - nums[p2]))) {
                        cha = min(cha, abs(target - nums[i] - nums[p1] - nums[p2]));
                        res = nums[p1] + nums[p2] + nums[i];
                    }
                    p2--;
                }
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums{1,1,1,0};
    int target = -100;
    Solution so;
    auto ans = so.threeSumClosest(nums, target);
    cout << ans;
    return 0;
}