
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++){
		if (nums[i] < target){
			continue;
		} else {
			return i;
		}
	}

	return nums.size();
    }
};


int main(void)
{
    vector<int> nums{1,3,5,6};
    int target = 3;
    int ans;
    Solution so;
    ans = so.searchInsert(nums, target);
    cout << ans << endl;

    return 0;
}
