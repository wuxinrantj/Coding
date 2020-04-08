
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 奇数只能有一个
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> nums('z' - 'A' + 1, 0);
        int odd = 0;
        for(int i = 0; i < s.size(); ++i) {
            nums[s[i] - 'A']++;
        }
        for(int j = 0; j < nums.size(); ++j) {
            if(nums[j] % 2 == 1) {
                odd ++;
            }
        }
        if(odd == 0) {
            return s.size() - odd;
        } else {
            return s.size() - odd + 1;
        }

    }
};

int main(void)
{
    string s = "abccccdd";

    Solution so;
    auto ans = so.longestPalindrome(s);
    cout << ans << endl;

    return 0;
}
