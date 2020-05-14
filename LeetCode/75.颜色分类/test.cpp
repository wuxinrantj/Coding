#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};

int main() {
    vector<int> nums{2,0,2,1,1,0};
    Solution so;
    so.sortColors(nums);
    for(int i = 0; i <nums.size(); ++i) {
        cout << nums[i] << ',';
    }
    return 0;
}