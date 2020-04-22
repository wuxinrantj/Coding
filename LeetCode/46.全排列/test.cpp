#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//回溯
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        // 记录走过的路径
        vector<int> track;
        backtrack(nums, track);
        return res;
    }

    void backtrack(vector<int>& nums, vector<int>& track) {
        if(nums.size() == track.size()) {
            res.push_back(track);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            vector<int>::iterator it = find(track.begin(), track.end(), nums[i]); 
            if (it != track.end()) {  //排除在 track 中已经选择过的数字；
                continue;
            }
            
            track.push_back(nums[i]);
            backtrack(nums, track);
            track.pop_back();
        }
    }
};

int main() {
    vector<int> nums{1,2,3};
    Solution so;
    auto ans = so.permute(nums);
    for(int i = 0; i < ans.size(); ++i) {
        for(int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << ',';
        }
        cout << endl;
    }
    return 0;
}
