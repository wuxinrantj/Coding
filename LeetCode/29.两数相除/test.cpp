#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 1) return dividend;
        else if(divisor == -1) {
            if(dividend > INT_MIN) return -dividend;
            else return INT_MAX;
        } else return dividend / divisor;
    }
};

int main() {
    int dividend = -2147483648;
    int divisor = -1;
    Solution so;
    auto ans = so.divide(dividend, divisor);
    cout << ans;
    return 0;
}