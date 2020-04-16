#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
private:
    deque<int> data;
public:
    void dqpush(int n) {
    while (!data.empty() && data.back() < n)
        data.pop_back();
    data.push_back(n);
    }

    int dqmax() { return data.front(); }

    void dqpop(int n) {
    if (!data.empty() && data.front() == n)
        data.pop_front();
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {if (i < k - 1) { //先填满窗⼝的前 k - 1
            dqpush(nums[i]);
            } else { // 窗⼝向前滑动
                dqpush(nums[i]);
                res.push_back(dqmax());
                dqpop(nums[i - k + 1]);
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums{1,3,-1,-3,5,3,6,7};
    int k = 3;

    Solution so;
    auto ans = so.maxSlidingWindow(nums, k);
    for(int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ',';
    }
}