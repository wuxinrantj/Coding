#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//回溯
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
public:
    void DFS(vector<int> &candidates, int start, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++) {
            path.push_back(candidates[i]);
            DFS(candidates, i, target - candidates[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        DFS(candidates, 0, target);

        return res;
    }
};

int main() {
    vector<int> candidates{2,3,5};
    int target = 8;
    Solution so;
    auto ans = so.combinationSum(candidates, target);
    for(int i = 0; i < ans.size(); ++i) {
        for(int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << ',';
        }
        cout << endl;
    }
    return 0;
}