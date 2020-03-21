/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
#include <math.h>
class Solution {
public:
    int reverse(int x) {
        long long b = 0;

        while (x != 0)
        {
            b = b * 10 + x % 10;
            x /= 10;
        }
        if (static_cast<int>(b) != b) {
        return 0;
        }
        return b;
    }
};
// @lc code=end

