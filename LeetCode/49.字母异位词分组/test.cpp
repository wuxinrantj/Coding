#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;
//引入一个hash表，索引是排序后的单词，值为结果vector的下标
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;  
        int count = 0;
        string tmp;
        unordered_map<string, int> work;
        for(auto str:strs)
        {
            tmp = str;
            sort(tmp.begin(),tmp.end());
            if(work.count(tmp)) {
                res[work[tmp]].push_back(str);
            } else {
                vector<string> vec(1, str);
                res.push_back(vec);
                work[tmp] = count ++;
            }
        }
        return res;
    }
};

int main(){
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution so;
    auto ans = so.groupAnagrams(strs);
    for(int i = 0; i < ans.size(); ++i) {
        for(int j = 0; j < ans[i].size(); ++j){
            cout << ans[i][j] << ',';
        }
        cout << endl;
    }
    return 0;
}