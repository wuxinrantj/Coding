#include <iostream>
#include <string>

using namespace std;
//双指针
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() > t.size()) return false;
        int i = 0, j = 0;
        while(i < s.size() && j < t.size()) {
            if(s[i] == t[j]) ++i;
            ++j;
        }
        return i == s.size();
    }
};

int main() {
    string s = "abc";
    string t = "ahbgdc";
    Solution so;
    auto ans = so.isSubsequence(s, t);
    cout << boolalpha << ans << endl;
    return 0;
}