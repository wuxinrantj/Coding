
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        char top;
        map<char,char> kuohao;
        kuohao[')'] = '(';
        kuohao[']'] = '[';
        kuohao['}'] = '{';

        for (int i = 0; i < s.size(); ++i)
        {
            if (kuohao.find(s[i]) == kuohao.end())
            {
                stack.push_back(s[i]);
            }
            else
            {
                if (stack.size() != 0)
                {
                    top = stack.back();
                    stack.pop_back();
                }

                if (kuohao[s[i]] != top)
                {
                    return false;
                }
            }
        }
        
        if (stack.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main(void)
{
    string strs = "{[]}";

    bool ans;
    Solution so;
    ans = so.isValid(strs);
    cout << boolalpha << ans << endl;

    return 0;
}
