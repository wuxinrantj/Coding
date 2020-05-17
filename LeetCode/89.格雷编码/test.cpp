#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 0) return {0};
        vector<int> ans = grayCode(n-1);
        for(int i = pow(2, n-1) - 1; i >= 0 ; i--)
            ans.push_back(ans[i] + pow(2, n-1));
        return ans;
    }
};

int main() {
    int n = 2;
    Solution so;
    auto ans = so.grayCode(n);
    for(int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ',';
    }
    return 0;
}