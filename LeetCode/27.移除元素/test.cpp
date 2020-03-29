
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()){
            return 0;
        }else{
            int j = 0;
            for (int i = 0; i < nums.size(); ++i){
                if (nums[i] != val){
                    nums[j] = nums[i];
                    j++;
                }
            }
            for (int k = 0; k < j; ++k){
                cout<<nums[k]<<' ';
            }
            cout<<endl;
            return j;
        }
    }
};

int main(void)
{
    vector<int> nums{3,2,2,3};
    int val = 3;
    int ans;
    Solution so;
    ans = so.removeElement(nums, val);
    cout << ans << endl;

    return 0;
}
