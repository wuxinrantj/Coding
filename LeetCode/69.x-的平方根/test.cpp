
#include <iostream>

using namespace std;

class Solution {
 public:
  int mySqrt(int x) {
    long root = x;
    //牛顿迭代法
    while (root * root > x) {
      root = (root * root + x) / (2 * root);
    }

    return root;
  }
};

int main(void)
{
    int x = 8;
    int ans;
    Solution so;
    ans = so.mySqrt(x);
    cout << ans << endl;

    return 0;
}
