
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// dp[i][j] 表示在⼦串 s[i..j] 中，最⻓回⽂⼦序列的⻓度为
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for(int i = 0; i < s.size(); ++i) {      //base case
            dp[i][i] = 1;
        }

        for(int i = s.size() - 1; i >= 0; --i) {    //反向遍历
            for(int j = i + 1; j < s.size(); ++j) {
                if(s[i] == s[j]) {    // 它俩⼀定在最⻓回⽂⼦序列中
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {   // s[i+1..j] 和 s[i..j-1] 谁的回⽂⼦序列更⻓？
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][s.size() - 1];

    }
};

int main(void)
{
    string s = "bbbab";

    int ans;
    Solution so;
    ans = so.longestPalindromeSubseq(s);
    cout << ans << endl;

    return 0;
}
