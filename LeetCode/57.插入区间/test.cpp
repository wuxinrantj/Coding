#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i;
        for(i = 0; i < intervals.size(); ++i) {
            if(intervals[i][1] < newInterval[0]) {
                res.push_back(intervals[i]);
            } else {
                break;
            }
        }
        res.push_back(newInterval);
        for(int j = i; j < intervals.size(); ++j) {
            if(intervals[j][0] > newInterval[1]) {
                res.push_back(intervals[j]);
            } else {
                res[i][0] = min(res[i][0], intervals[j][0]);
                res[i][1] = max(res[i][1], intervals[j][1]);
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> intervals{{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> newInterval{4, 8};
    Solution so;
    auto ans = so.insert(intervals, newInterval);
    for(int i = 0; i < ans.size(); ++i) {
        cout << '{' << ans[i][0] << ',' << ans[i][1] << "},";
    }
    return 0;
}