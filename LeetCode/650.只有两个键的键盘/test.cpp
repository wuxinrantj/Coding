
#include <iostream>
#include <vector>
using namespace std;
// 素数分解 https://leetcode-cn.com/problems/2-keys-keyboard/solution/zhi-you-liang-ge-jian-de-jian-pan-by-leetcode/
class Solution {
public:
    int minSteps(int n) {
        int ans = 0, d = 2;
        while (n > 1) {
            while (n % d == 0) {
                ans += d;
                n /= d;
            }
            d++;
        }
        return ans;
    }
};

int main()
{
    int n = 3;

    Solution so;
    auto ans = so.minSteps(n);

    cout << ans << endl;

    return 0;
}
