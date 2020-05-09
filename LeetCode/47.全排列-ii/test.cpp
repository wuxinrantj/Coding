#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//回溯
class Solution {
public:
    vector<vector<int>> res;
    vector<bool> marked; 
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // 记录走过的路径
        vector<int> track;
        marked = vector<bool>(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, track);
        return res;
    }

    void backtrack(vector<int>& nums, int start, vector<int>& track) {
        if(nums.size() == start) {
            res.push_back(track);
            return;
        }
        
        for(int i = 0; i < nums.size(); ++i){
            if(marked[i])
                continue;

            if(i > 0 && nums[i] == nums[i-1] && marked[i-1] == false) {
                continue;
            }
            track.push_back(nums[i]);
            marked[i] = true;
            backtrack(nums, start + 1, track);
            track.pop_back();
            marked[i] = false;
        }
        return;
    }
};

int main() {
    vector<int> nums{1,1,3};
    Solution so;
    auto ans = so.permuteUnique(nums);
    for(int i = 0; i < ans.size(); ++i) {
        for(int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << ',';
        }
        cout << endl;
    }
    return 0;
}
