#include <iostream>
#include <vector>

using namespace std;
// 回溯
class Solution {
public:
    bool isValid(string ip){
        int val = stoi(ip);  // stoi（字符串，起始位置，n进制），将 n 进制的字符串转化为十进制
        if (val > 255)    return false;
        if (ip.size() >= 2 && ip[0] == '0')    return false;
        return true;
    }

    void dfs(string& s, int pos, vector<string> &path, vector<string>& res) {
        //4组，每组最多3位数字
        int maxLen = (4 - path.size()) * 3;
        if (s.size() - pos > maxLen)    return;
        if (path.size() == 4 && pos == s.size()) { //放 . 
            string ans = "";
            for (int i = 0; i < 4; ++i) {
                ans += path[i];
                if (i != 3)    ans += ".";
            }
            res.push_back(ans);
            return;
        }
        //回溯算法的典型模式，循环递归
        for (int i = pos; i < s.size() && i <= pos + 2; ++i) {
            string ip = s.substr(pos, i - pos + 1);
            if (!isValid(ip))    continue;
            path.push_back(ip);
            dfs(s, i + 1, path, res);
            path.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s){
        vector<string> res;
        if (s.size() == 0 || s.size() < 4)    return res;
        vector<string> path;//存储从根开始的到叶子节点的满足条件的路径,因为最多3位数字一组，所以同一层横向循环时尝试最多3个位的长度
        dfs(s, 0, path, res);
        return res;
    }
};

int main() {
    string s = "25525511135";
    Solution so;
    auto ans = so.restoreIpAddresses(s);
    for(int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ',';
    }
    return 0;
}