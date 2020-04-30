#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len - 3; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i + 1; j < len - 2; ++j){
                if(j > i + 1 && nums[j] == nums[j-1]) continue;
                int p1 = j + 1, p2 = len - 1;
                while(p1 < p2){
                    if(nums[i] + nums[j] + nums[p1] + nums[p2] < target){
                        p1++;
                    } else if (nums[i] + nums[j] + nums[p1] + nums[p2] == target){
                        if(p1 == j+1){
                            vector<int> vtemp{nums[i], nums[j], nums[p1], nums[p2]};
                            res.push_back(vtemp);
                            vtemp.clear();
                        }else if(nums[p1] != nums[p1-1]){
                            vector<int> vtemp{nums[i], nums[j], nums[p1], nums[p2]};
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
    vector<int> nums{1, 0, -1, 0, -2, 2};
    int target = 0;
    Solution so;
    auto ans = so.fourSum(nums, target);
    for(int i = 0; i < ans.size(); ++i) {
        for(int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}