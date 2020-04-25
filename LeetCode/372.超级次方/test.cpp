#include <iostream>
#include <vector>

using namespace std;
//(a * b) % k = (a % k)(b % k) % k
class Solution {
public:
    int base = 1337;
    // 计算 a 的 k 次方然后与 base 求模的结果
    int mypow(int a, int k) {
        a %= base;
        int res = 1;
        for (int i = 0; i < k; ++i) {
            res *= a;
            res %= base;
        }
        return res;
    }

    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int last = b.back();
        b.pop_back();

        int part1 = mypow(a, last);
        int part2 = mypow(superPow(a, b), 10);
        return (part1 * part2) % base;
    }

};

int main() {
    int a = 2;
    vector<int> b{1,0};
    Solution so;
    auto ans = so.superPow(a, b);
    cout << ans << endl;
    return 0;
}