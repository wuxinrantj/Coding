
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }

        auto str = countAndSay(n-1);
        int count = 1;
        string res = "";
        
        for(int i = 0;i < str.size(); ++i){
            if(str[i] == str[i+1]){ 
                count++;
                continue;
            } else {
                res += to_string(count) + str[i];
                count = 1;
            }
        }
        return res;
    }
};

int main(void)
{
    int n = 7;
    string ans;
    Solution so;
    ans = so.countAndSay(n);
    cout << ans << endl;

    return 0;
}
