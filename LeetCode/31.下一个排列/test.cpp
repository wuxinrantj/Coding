#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1) return;
        int pos = nums.size() - 1;
        while(pos > 0) {
            if(nums[pos] > nums[pos - 1]) {
                break;
            }
            --pos;
        }
        reverse(nums.begin() + pos, nums.end());  //逆序
		if (pos > 0){
			for (int i = pos; i < nums.size(); i++){ //寻找第一个大于nums[pos - 1]的数
				if (nums[i] > nums[pos - 1]){
					swap(nums[i], nums[pos - 1]); //交换
					break;
				}
			}
		}
    }
};

int main() {
    vector<int> nums{1,3,2};
    Solution so;
    so.nextPermutation(nums);
    for(int i = 0; i< nums.size(); ++i) {
        cout << nums[i] << ',';
    }
    return 0;
}