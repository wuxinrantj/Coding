
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// dp[i][j] 表示⼦串 s[i..j] 是否是回文
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2) {
            return s;
        }
        int maxlen = 1;
        int start = 0;
		string str = "";
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

        for(int j = 1; j < s.size(); ++j) {
            for(int i = 0; i <= j; ++i) {
                if(s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1] == true)) {
                    dp[i][j] = true;
                    if(j - i + 1 > maxlen)
                    {
                        maxlen = j - i + 1;
                        start = i;
                    }
                }
                else
                    dp[i][j] = false;
            }
        }
        return s.substr(start, maxlen);

    }
};

int main(void)
{
    string s = "babad";

    string ans;
    Solution so;
    ans = so.longestPalindrome(s);
    cout << ans << endl;

    return 0;
}
