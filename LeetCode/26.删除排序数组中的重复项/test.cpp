
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()){
            return 0;
        }else{
            int j = 0;
            for (int i = 0; i < nums.size(); ++i){
                if (nums[j] < nums[i]){
                    nums[j+1] = nums[i];
                    ++j;
                }
            }
            for (int k = 0; k < j+1; ++k){
                cout<<nums[k]<<' ';
            }
            cout<<endl;
            return ++j;
        }
    }
};

int main(void)
{
    vector<int> nums{0,0,1,1,1,2,2,3,3,4};

    int ans;
    Solution so;
    ans = so.removeDuplicates(nums);
    cout << ans << endl;

    return 0;
}
