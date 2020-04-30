#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;
//回溯
class Solution {
public:
    map<char, string> phone{ {'1', ""},
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
        {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    string temp;
    vector<string> res;

    void backtrack(int index, string digits) {
        if(index == digits.size()) {
            res.push_back(temp);
            return;
        }

        for(int i = 0; i < phone[digits[index]].size(); i++) {
            temp.push_back(phone[digits[index]][i]);
            backtrack(index + 1, digits);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) {
            return res;
        }
        backtrack(0, digits);

        return res;
    }
};

int main() {
    string digits = "23";
    Solution so;
    auto ans = so.letterCombinations(digits);
    for(int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ",";
    }
    return 0;
}