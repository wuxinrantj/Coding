#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        string s = string("123456789").substr(0, n);
        
        --k;
        while(k > 0) {
            long long i = k/fac(n - 1);
            res.push_back(s[i]);
            s.erase(s.begin() + i);
            k %= fac(n - 1);
            --n;
        }
        return res + s;
    }

    int fac(int n) {
        long long ans = 1;
        for(int i = 1; i <= n; ++i) {
            ans *= i;
        }
        return ans;
    }
};

int main() {
    int n = 4;
    int k = 9;
    Solution so;
    auto ans = so.getPermutation(n, k);
    cout << ans << endl;
    return 0;
}