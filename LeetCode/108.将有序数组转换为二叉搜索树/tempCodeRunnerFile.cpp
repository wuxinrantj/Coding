class Solution {
// public:
//     TreeNode* sortedArrayToBST(vector<int>& nums) {
//         if(nums.size() == 0) {
//             return nullptr;
//         }

//         int mid = nums.size()/2;
//         TreeNode* root = new TreeNode(nums[mid]);
//         root->left = sortedArrayToBST(nums(nums.begin(),nums.begin() + mid));
//         root->right = sortedArrayToBST(nums(nums.begin() + mid, nums.end()));
//     }
// };