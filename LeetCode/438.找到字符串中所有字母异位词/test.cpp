#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
//76改
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int left = 0, right = 0;
        unordered_map<char, int> window;
        unordered_map<char, int> needs;
        for (char c : p) needs[c]++;   

        int match = 0;   
        while (right < s.size()) {
            char c1 = s[right];
            if (needs.count(c1)) {
                window[c1]++;
                if (window[c1] == needs[c1])
                match++;
            }
            right++;

            while (match == needs.size()) {
                if (right - left == p.size()) {   //大小合适就加入结果
                    res.push_back(left);       
                }
                char c2 = s[left];
                if (needs.count(c2)) {
                    window[c2]--;
                    if (window[c2] < needs[c2])
                    match--;
                }
                left++;
            }
        }
        return res;
    }
};

int main() {
    string s = "cbaebabacd";
    string p = "abc";

    Solution so;
    auto ans = so.findAnagrams(s, p);
    for(int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ',';
    }
    return 0;
}