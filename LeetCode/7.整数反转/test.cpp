
#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {

        long long b = 0;
        while (x != 0)
        {
            b = b * 10 + x % 10;
            x /= 10;
        }
        if (static_cast<int>(b) != b) {   //强制转换
        return 0;
        }
        return b;
    }
};

int main(void)
{

    int x = -2147483648;
    int ans;
    Solution so;
    ans = so.reverse(x);
    cout << ans << endl;

    return 0;
}
