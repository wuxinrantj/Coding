#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        if(A.size() == 0 || B.size() == 0) {
            return {};
        }
        vector<vector<int>> res;
        int i = 0;
        int j = 0;

        while(i < A.size() && j < B.size()) {
            auto a0 = A[i][0];
            auto a1 = A[i][1];
            auto b0 = B[j][0];
            auto b1 = B[j][1];
            if(a0 <= b1 && a1 >= b0) {
                res.push_back({max(a0, b0), min(a1, b1)});
            }
            if(a1 < b1) {
                i++;
            } else {
                j++;
            }
        }
        return res;
    }
};

int main() {
    vector<vector<int>> A{{0,2},{5,10},{13,23},{24,25}};
    vector<vector<int>> B{{1,5},{8,12},{15,24},{25,26}};
    Solution so;
    auto ans = so.intervalIntersection(A, B);
    for(int i = 0; i < ans.size(); ++i) {
        for(int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << ',';
        }
        cout << endl;
    }
    return 0;
}