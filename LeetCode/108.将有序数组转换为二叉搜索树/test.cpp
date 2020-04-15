#include "../binarytree.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0) {
            return nullptr;
        }

        int mid = nums.size()/2;
        TreeNode* root = new TreeNode(nums[mid]);
        vector<int> left(nums.begin(),nums.begin() + mid);
        root->left = sortedArrayToBST(left);
        vector<int> right(nums.begin() + mid + 1, nums.end());
        root->right = sortedArrayToBST(right);

        return root;
    }
};

int main() {
    vector<int> nums{-10,-3,0,5,9};
    Solution so;
    auto ans = so.sortedArrayToBST(nums);
    prettyPrintTree(ans);

    return 0;
}


