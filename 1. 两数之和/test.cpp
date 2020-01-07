
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> static twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.count(target - nums[i])) return { hash[target - nums[i]], i };
            hash[nums[i]] = i;
        }
        return { -1, -1 };
    }
};


int main(void)
{

    int n = 4;
    int target = 9;
    vector<int> id;

    int a[n] = {2,3,4,5};
    vector<int> nums(a, a + n);
    
    id = Solution::twoSum(nums, target);
    for (vector<int>::iterator it = id.begin(); it < id.end(); it++) {
        cout << *it<<" ";
    }

    return 0;
}
