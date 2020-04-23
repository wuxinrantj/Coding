#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//先对宽度 w 进⾏升序排序，如果遇到 w 相同的情况，则按照⾼度 h 降序排序。之后把所有的 h 作为⼀个数组，在这个数组上计算 LIS 的⻓度
class Solution {
public:
    static bool cmp(vector<int>& p, vector<int>& q) {
        if(p[0] == q[0]) {
            return p[1] > q[1];
        }
        return p[0] < q[0];
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.size() == 0) return 0;
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> height;
        for(int i = 0; i < envelopes.size(); ++i){
            height.push_back(envelopes[i][1]);
        }
        return LIS(height);
    }

    int LIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for(int i = 0; i < nums.size(); ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
    
};

int main() {
    vector<vector<int>> envelopes{{5,4},{6,4},{6,7},{2,3}};
    Solution so;
    auto ans = so.maxEnvelopes(envelopes);
    cout << ans << endl;
    return 0;
}