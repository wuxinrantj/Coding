#include <iostream>
#include <vector>

using namespace std;
// 1. 三数和变为两数和  2. 双指针
class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len - 2; i++){
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])){  //去重
                int p1 = i + 1, p2 = len - 1; 
                while(p1 < p2){
                    if(nums[p1] + nums[p2] < -nums[i]){
                        p1++;
                    } else if (nums[p1] + nums[p2] == -nums[i]){
                        if(p1 == i+1){
                            vector<int> vtemp{nums[i], nums[p1], nums[p2]};
                            res.push_back(vtemp);
                            vtemp.clear();
                        }else if(nums[p1] != nums[p1-1]){
                            vector<int> vtemp{nums[i], nums[p1], nums[p2]};
                            res.push_back(vtemp);
                            vtemp.clear();
                        }
                        p1++,p2--;
                    } else {
                        p2--;
                    }
                }
            }
        }
        return res;

    }
};

int main() {
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    Solution so;
    auto ans = so.threeSum(nums);
    for(int i = 0; i < ans.size(); ++i) {
        for(int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}