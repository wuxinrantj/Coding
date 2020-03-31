
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty()) {
            return 0;
        }
        int last = s.size()-1;
        while(last >= 0 && s[last]==' ')
        {
            s.erase(last);
            --last;
        }
        auto first = s.find_last_of(' ');
        return s.length() - first - 1;
    }
};

int main(void)
{
    string s = "Hello World";
    int ans;
    Solution so;
    ans = so.lengthOfLastWord(s);
    cout << ans << endl;

    return 0;
}
