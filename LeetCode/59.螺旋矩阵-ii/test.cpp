#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 1));
        int u = 0;
        int d = n - 1;
        int l = 0;
        int r = n - 1;
        int count = 1;
        while(true) {
            for(int i = l; i <= r; ++i) res[u][i] = count++;
            if(++u > d) break;
            for(int i = u; i <= d; ++i) res[i][r] = count++;
            if(--r < l) break;
            for(int i = r; i >= l; --i) res[d][i] = count++;
            if(--d < u) break;
            for(int i = d; i >= u; --i) res[i][l] = count++;
            if(++l > r) break;
        }
        return res;
    }
};

int main() {
    int n = 3;
    Solution so;
    auto ans = so.generateMatrix(n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << ans[i][j] << ',';
        }
        cout << endl;
    }
    return 0;
}