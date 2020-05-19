#include <iostream>
#include <vector>

using namespace std;
// dp[i][j] s的前j个和t的前i个字符串的不同子序列
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<long long>> dp(t.size() + 1, vector<long long>(s.size() + 1,0));

        for(int i = 0; i < t.size(); ++i) {
            for(int j = 0; j < s.size(); ++j) {
                if(i == 0) dp[i][j] = 1;
                if (t[i] == s[j]) dp[i+1][j+1] = dp[i+1][j] + dp[i][j];  // 左边和左上
                else dp[i+1][j+1] = dp[i+1][j];
            }
        }
        return dp[t.size()][s.size()];
    }
};

int main() {
    string s = "babgbag";
    string t = "bag";
    Solution so;
    auto ans = so.numDistinct(s, t);
    cout << ans;
    return 0;
}