#include <iostream>
#include <vector>
#include <string>

using namespace std;
//回溯
//对于一个「合法」的括号字符串组合 p，必然对于任何 0 <= i < len(p) 都有：子串 p[0..i] 中左括号的数量都大于或等于右括号的数量。
class Solution {
public:
    vector<string> res;
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {};
        string track;
        // 可用的左括号和右括号数量初始化为 n
        backtrack(n, n, track);
        return res;
    }

    // 可用的左括号数量为 left 个，可用的右括号数量为 rgiht 个
    void backtrack(int left, int right, string& track) {
        // 若左括号剩下的多，说明不合法
        if (right < left) return;
        // 数量小于 0 肯定是不合法的
        if (left < 0 || right < 0) return;
        // 当所有括号都恰好用完时，得到一个合法的括号组合
        if (left == 0 && right == 0) {
            res.push_back(track);
            return;
        }

        // 尝试放一个左括号
        track.push_back('('); // 选择
        backtrack(left - 1, right, track);
        track.pop_back(); // 撤消选择

        // 尝试放一个右括号
        track.push_back(')'); // 选择
        backtrack(left, right - 1, track);
        track.pop_back(); // 撤消选择
    }
};

int main() {
    int n = 3;
    Solution so;
    auto ans = so.generateParenthesis(n);
    for(int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}