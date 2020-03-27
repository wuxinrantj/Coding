
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
        {
            return "";
        }
        
        string lcp="";
        for (int i = 0; i < strs[0].size(); ++i)
        {
            for (int j = 1; j < strs.size(); ++j)
            {
                if (strs[0][i] != strs[j][i])
                {
                    return lcp;
                }
            }
            lcp += strs[0][i];
        }
        return lcp;
    }
};

int main(void)
{
    vector<string> strs{"flower","flow","flight"};

    string ans;
    Solution so;
    ans = so.longestCommonPrefix(strs);
    cout << ans << endl;

    return 0;
}
