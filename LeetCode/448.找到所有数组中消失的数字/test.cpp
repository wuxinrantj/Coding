
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[abs(nums[i]) - 1] > 0) {
                nums[abs(nums[i]) - 1] *= -1;
            }
        }
        for(int i = 1; i <= nums.size(); ++i) {
            if(nums[i - 1] > 0) {
                res.push_back(i);
            }
        }
        return res;

    }
};

int main()
{
    vector<int> nums{4,3,2,7,8,2,3,1};
    Solution so;
    auto ans = so.findDisappearedNumbers(nums);

    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << ",";
    }	

    return 0;
}
