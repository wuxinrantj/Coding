
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};

int main(void)
{
    string haystack = "aaa";
    string needle = "aa";
    int ans;
    Solution so;
    ans = so.strStr(haystack, needle);
    cout << ans << endl;

    return 0;
}
