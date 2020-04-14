/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (41.79%)
 * Likes:    242
 * Dislikes: 0
 * Total Accepted:    65.9K
 * Total Submissions: 156.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 * 
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最小深度  2.
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
 public:
  int minDepth(TreeNode* root) {
    if (!root) {
      return 0;
    }

    auto leftDepth = minDepth(root->left);
    auto rightDepth = minDepth(root->right);
    // 处理只有左子树或者右子树的情况或者叶子节点
    if (root->left == nullptr || root->right == nullptr)
        return leftDepth + rightDepth + 1;    //必然有一个为0

    // 同时存在左右子树
    return 1 + min(leftDepth, rightDepth);
  }
};
// @lc code=end

