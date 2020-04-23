#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& p, vector<int>& q) {
        return p[0] < q[0];   //按start排序
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) {
            return {};
        }
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), cmp);
        res.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); ++i) {
            auto cur = intervals[i];
            auto last = res.back();
            if(cur[0] <= last[1]) {
                res.back()[1] = max(last[1], cur[1]);
            } else {
                res.push_back(cur);
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> intervals{{1,4}, {4,5}};
    Solution so;
    auto ans = so.merge(intervals);
    for(int i = 0; i < ans.size(); ++i) {
        for(int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << ',';
        }
        cout << endl;
    }
    return 0;
}