
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char,int> roman;//初始化哈希表
        // roman.insert(map<char,int>::value_type('I',1));
        // roman.insert(map<char,int>::value_type('V',5));
        // roman.insert(map<char,int>::value_type('X',10));
        // roman.insert(map<char,int>::value_type('L',50));
        // roman.insert(map<char,int>::value_type('C',100));
        // roman.insert(map<char,int>::value_type('D',500));
        // roman.insert(map<char,int>::value_type('M',1000));
        roman['I'] = 1;
        roman['V'] = 5;
        roman['X'] = 10;
        roman['L'] = 50;
        roman['C'] = 100;
        roman['D'] = 500;
        roman['M'] = 1000;

        int result = 0;
        int i;
        for (i = 0; i < s.length()-1; ++i)
        {
            if (roman[s[i]] < roman[s[i + 1]])
            {
                result -= roman[s[i]];
            }
            else
            {
                result += roman[s[i]];
            }
        }
        return result + roman[s[i]];
    }
};

int main(void)
{

    string s = "MCMXCIV";
    int ans;
    Solution so;
    ans = so.romanToInt(s);
    cout << ans << endl;

    return 0;
}
