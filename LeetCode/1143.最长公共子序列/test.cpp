#include <iostream>
#include <string>
#include <vector>

using namespace std;
//dp[i][j] 的含义是：对于 s1[1..i] 和 s2[1..j] ，它们的 LCS ⻓度是 dp[i][j]
//dp[0][..] 和 dp[..][0] 都应该初始化为 0，这就是 base case。
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.empty() || text2.empty()) return 0;

        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for(int i = 1; i < text1.size() + 1; ++i) {
            for(int j = 1; j < text2.size() + 1; ++j) {
                if(text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[text1.size()][text2.size()];

    }
};

int main() {
    string text1 = "abcde";
    string text2 = "ace";

    Solution so;
    auto ans = so.longestCommonSubsequence(text1, text2);
    cout << ans << endl;

    return 0;
}