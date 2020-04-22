#include <iostream>
#include <vector>

using namespace std;
//回溯
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        if(k <= 0 || n <= 0) {
            return res;
        }
        vector<int> track;
        backtrack(n, k, 1, track);
        return res;
    }

    void backtrack(int n, int k, int start, vector<int>& track) {  //k 限制了树的高度，n 限制了树的宽度
        // 到达树的底部
        if (k == track.size()) {
            res.push_back(track);
            return;
        }
        for (int i = start; i <= n; i++) {
            // 做选择
            track.push_back(i);
            // 回溯
            backtrack(n, k, i + 1, track);
            // 撤销选择
            track.pop_back();
        }
    }
};

int main() {
    int n = 4;
    int k = 2;
    Solution so;
    auto ans = so.combine(n,k);
    for(int i = 0; i < ans.size(); ++i) {
        for(int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << ',';
        }
        cout << endl;
    }
    return 0;
}
