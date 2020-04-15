/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
 *
 * https://leetcode-cn.com/problems/delete-node-in-a-bst/description/
 *
 * algorithms
 * Medium (38.96%)
 * Likes:    169
 * Dislikes: 0
 * Total Accepted:    11.3K
 * Total Submissions: 28.5K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n3'
 *
 * 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key
 * 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。
 * 
 * 一般来说，删除节点可分为两个步骤：
 * 
 * 
 * 首先找到需要删除的节点；
 * 如果找到了，删除它。
 * 
 * 
 * 说明： 要求算法时间复杂度为 O(h)，h 为树的高度。
 * 
 * 示例:
 * 
 * 
 * root = [5,3,6,2,4,null,7]
 * key = 3
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2   4   7
 * 
 * 给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
 * 
 * 一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 4   6
 * ⁠/     \
 * 2       7
 * 
 * 另一个正确答案是 [5,2,6,null,4,null,7]。
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 2   6
 * ⁠  \   \
 * ⁠   4   7
 * 
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
    TreeNode* getmin(TreeNode* node) {    //右子树最小的值在最左边
      while (node->left != nullptr) {
        node = node->left;
      }
      return node;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
      if(!root) {
        return nullptr;
      }

      if(root->val == key) {
        if(root->left == nullptr) return root->right;    //key为叶子结点或者只有一个子节点
        if(root->right == nullptr) return root->left;

        auto minnode = getmin(root->right);             //左右子都存在，找右子树最小的值替换，并删除
        root->val = minnode->val;
        root->right = deleteNode(root->right, minnode->val);
      } else if (root->val < key) {
        root->right = deleteNode(root->right, key);
      } else {
        root->left = deleteNode(root->left, key);
      }

      return root;
    }
};
// @lc code=end

