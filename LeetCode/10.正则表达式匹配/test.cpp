#include <iostream>
#include <string>

using namespace std;
//暴力递归
class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();

        bool first_match = s[0] && (s[0] == p[0] || p[0] == '.');
        if (p[1] == '*') {
            return isMatch(s, p.substr(2, p.size())) || (first_match && isMatch(s.substr(1, s.size()), p));
        }
        else {
            return first_match && isMatch(s.substr(1, s.size()), p.substr(1, p.size()));
        }
    }
};

int main() {
    string s = "mississippi";
    string p = "mis*is*p*.";

    Solution so;
    auto ans = so.isMatch(s, p);
    cout << boolalpha << ans << endl;

    return 0;
}