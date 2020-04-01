
#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
      //斐波那契公式
      double fibn = pow((1 + sqrt(5)) / 2, n+1) - pow((1 - sqrt(5)) / 2, n+1);
      return int(fibn / sqrt(5));
    }
};

int main(void)
{
    int n = 5;
    int ans;
    Solution so;
    ans = so.climbStairs(n);
    cout << ans << endl;

    return 0;
}
