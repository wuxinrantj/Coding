#include <iostream>

using namespace std;
// 二分递归
class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        if(x == 0) return 0;
        if(n == -1) return 1 / x;
        double half = myPow(x, n / 2);   //奇偶
        double rest = myPow(x, n % 2);
        return rest * half * half;
    }
};

int main() {
    double x = 2;
    int n = -4;
    Solution so;
    auto ans = so.myPow(x, n);
    cout << ans << endl;
}