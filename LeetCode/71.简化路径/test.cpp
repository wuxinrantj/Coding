#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        vector<string> strs;
        string res = "", tmp = "";
        while(getline(ss, tmp, '/')) {
            if(tmp == "" || tmp == ".")
                continue;
            else if(tmp == ".." && !strs.empty())
                strs.pop_back();
            else if(tmp != "..")
                strs.push_back(tmp);
        }
        for(string str:strs) 
            res +=  "/" + str;
        if(res.empty())
            return "/";
        return res;
    }
};

int main(){
    string path = "/a/./b/../../c/";
    Solution so;
    auto ans = so.simplifyPath(path);
    cout << ans;
    return 0;
}
