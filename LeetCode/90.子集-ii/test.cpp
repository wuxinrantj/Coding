#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//回溯
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> track;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, track);
        return res;
    }

    void backtrack(vector<int>& nums, int start, vector<int>& track) {
        res.push_back(track);

        for (int i = start; i < nums.size(); i++) {
            if(i > start && nums[i - 1] == nums[i]) // 如果有重复元素
                continue;
            track.push_back(nums[i]);
            backtrack(nums, i + 1, track);
            track.pop_back();
        }
    }
};

int main() {
    vector<int> nums{4,4,4,1,4};
    Solution so;
    auto ans = so.subsetsWithDup(nums);
    for(int i = 0; i < ans.size(); ++i) {
        for(int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << ',';
        }
        cout << endl;
    }
    return 0;
}
