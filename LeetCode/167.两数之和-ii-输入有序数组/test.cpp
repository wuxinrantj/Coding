#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        while(left < right) {
            int sum = numbers[left] + numbers[right];
            if(sum == target){
                return {left + 1, right + 1};
            } else if(sum < target) {
                left++;
            } else if(sum > target) {
                right--;
            }
        }
        return {-1, -1};
    }
};

int main() {
    vector<int> numbers{2, 7, 11, 15};
    int target = 18;
    
    Solution so;
    auto ans = so.twoSum(numbers, target);
    for(int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ',';
    }
    return 0;
}