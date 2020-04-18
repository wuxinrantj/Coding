#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
//滑动窗口
class Solution {
public:
    string minWindow(string s, string t) {
        int start = 0, minLen = INT_MAX;
        int left = 0, right = 0;
        unordered_map<char, int> window;
        unordered_map<char, int> needs;
        for (char c : t) needs[c]++;   

        int match = 0;   //匹配的字符个数
        while (right < s.size()) {
            char c1 = s[right];
            if (needs.count(c1)) {
                window[c1]++;
                if (window[c1] == needs[c1])
                match++;
            }
            right++;   //窗口先全包含
            while (match == needs.size()) {
                if (right - left < minLen) {
                    // 更新最⼩⼦串的位置和⻓度
                    start = left;
                    minLen = right - left;
                }
                char c2 = s[left];
                if (needs.count(c2)) {
                    window[c2]--;
                    if (window[c2] < needs[c2])
                    match--;
                }
                left++;   //再缩小窗口大小直到不再全包含
            }
        }
        return minLen == INT_MAX ?
        "" : s.substr(start, minLen);
    }
};

int main() {
    string s = "ADOBECODEBANC";
    string t = "ABC";

    Solution so;
    auto ans = so.minWindow(s, t);
    cout << ans << endl;
    return 0;
}