/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 *
 * https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (39.75%)
 * Likes:    381
 * Dislikes: 0
 * Total Accepted:    33.3K
 * Total Submissions: 83.7K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个非空二叉树，返回其最大路径和。
 * 
 * 本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 * 
 * 输出: 6
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-10,9,20,null,null,15,7]
 * 
 * -10
 * / \
 * 9  20
 * /  \
 * 15   7
 * 
 * 输出: 42
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int maxPathSum(TreeNode* root, int &val) {
        
        if (root == nullptr) return 0;
        int left  = std::max(maxPathSum(root->left,  val), 0);
        int right = std::max(maxPathSum(root->right, val), 0);

        int lmr = root->val + left + right; 
        val = std::max(val, lmr);

        return root->val + std::max(left, right);// 沿着更大的一个分支返回
    }

public:
    int maxPathSum(TreeNode* root) {

        int val = INT_MIN;
        maxPathSum(root, val);
        return val;
    }
};
// @lc code=end

