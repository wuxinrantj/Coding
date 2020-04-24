#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//暴力->二分查找
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        auto maxnum = *max_element(piles.begin(),piles.end());
        int left = 1, right = maxnum + 1;
        while (left < right) {
            // 防⽌溢出
            int mid = left + (right - left) / 2;
            if (caneat(piles, mid, H)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool caneat(vector<int>& piles, int speed, int H){
        long long time = 0;
        for(auto n : piles) {
            int m = n / speed;
            if(n % speed > 0) {
                ++ m;
            }
            time += m;
            if(time > H) return false;
        }
        return time <= H;
    }
};

int main() {
    vector<int> piles{332484035, 524908576, 855865114, 632922376, 222257295, 690155293, 112677673, 679580077, 337406589, 290818316, 877337160, 901728858, 679284947, 688210097, 692137887, 718203285, 629455728, 941802184}; 
    int H = 823855818;
    Solution so;
    auto ans = so.minEatingSpeed(piles, H);
    cout << ans << endl;
    return 0;
}