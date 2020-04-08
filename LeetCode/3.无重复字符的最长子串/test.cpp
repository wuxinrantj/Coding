
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;
// 滑动窗口 从左删除到重复字符
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_set<char> window;
        int maxlen = 0;
        int left = 0;
        for(int i = 0; i < s.size(); ++i) {
            while (window.find(s[i]) != window.end()){
                window.erase(s[left]);
                left ++;
            }
            maxlen = max(maxlen, i - left + 1);
            window.insert(s[i]);
        }
        return maxlen;
        
    }
};


int main(void)
{
    string s = "abcabcbb";

    Solution so;
    auto ans = so.lengthOfLongestSubstring(s);
    cout << ans << endl;

    return 0;
}
