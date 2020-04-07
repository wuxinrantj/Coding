
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// dp[i][j] 表示 word1 的前 i 个字母和 word2 的前 j 个字母之间的编辑距离
class Solution {
public:
    int minDistance(string word1, string word2) {
        
        auto len1 = word1.size();
        auto len2 = word2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

        for(int i = 1; i <= len1; ++i) {
            dp[i][0] = i;
        }
        for(int i = 1; i <= len2; ++i) {
            dp[0][i] = i;
        }

        for(int i = 1; i <= len1; ++i) {
            for(int j = 1; j<= len2; ++j) {
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1});
                // dp[i - 1][j] 表示删除操作
                // dp[i][j - 1] 表示插入操作
                // dp[i - 1][j - 1] 表示替换操作
                }
            }
        }
        return dp[len1][len2];
    }
};

int main(void)
{
    string word1 = "intention";
    string word2 = "execution";
    int ans;
    Solution so;
    ans = so.minDistance(word1, word2);
    cout << ans << endl;

    return 0;
}
