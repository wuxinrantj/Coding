#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric> 
using namespace std;
//暴力->二分查找
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        auto maxnum = *max_element(weights.begin(),weights.end());
        int left = maxnum;
        int right = accumulate(weights.begin(),weights.end(),1);  //累计求和
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canship(weights, mid, D)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool canship(vector<int>& weights, int cap, int D){
        int i = 0;
        for (int day = 0; day < D; ++day) {
            int maxCap = cap;
            while ((maxCap -= weights[i]) >= 0) {
                ++i;
                if (i == weights.size())
                    return true;
            }
        }
        return false;
    }
};

int main() {
    vector<int> weights{1,2,3,4,5,6,7,8,9,10}; 
    int D = 5;
    Solution so;
    auto ans = so.shipWithinDays(weights, D);
    cout << ans << endl;
    return 0;
}