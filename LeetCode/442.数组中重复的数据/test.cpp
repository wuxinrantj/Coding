
#include <iostream>
#include <vector>

using namespace std;
//将出现过的数字作为数组的index，将该index下的数取相反数，如果值为index的数字再出现一次那么这个数字就出现了两次。
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(auto v:nums){
            v = abs(v);        //避免index为负
            if(nums[v-1] < 0) 
                res.push_back(v);
            else 
                nums[v-1] = -nums[v-1];
        }
        return res;

    }
};

int main()
{
    vector<int> nums{4,3,2,7,8,2,3,1};
    Solution so;
    auto ans = so.findDuplicates(nums);

    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << ",";
    }	

    return 0;
}
