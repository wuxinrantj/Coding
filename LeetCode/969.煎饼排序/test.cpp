#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//递归    先把最大的翻到最下面，再递归n-1
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int N = A.size();
        vector<int> res;
        for (int i = N - 1; i > 0; --i) {
            int j = max_element(A.begin(), A.begin() + i + 1) - A.begin();
            if (j > 0) {
                reverse(A.begin(), A.begin() + j + 1);
                res.push_back(j + 1);
            }
            reverse(A.begin(), A.begin() + i + 1);
            res.push_back(i + 1);
        }
        return res;
    }
};

int main() {
    vector<int> A{3,2,4,1};
    Solution so;
    auto ans = so.pancakeSort(A);
    for(int i = 0; i< ans.size(); ++i) {
        cout << ans[i] << ',';
    }
    return 0;
}