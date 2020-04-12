/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (67.34%)
 * Likes:    184
 * Dislikes: 0
 * Total Accepted:    31K
 * Total Submissions: 45.8K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return post_order(0, inorder.size() - 1, 0, inorder.size() - 1, inorder, postorder);
    }

    TreeNode *post_order(int leftin, int rightin, int leftpost, int rightpost, vector<int> &in, vector<int> &post) {
        if(leftin > rightin || leftpost > rightpost) return NULL;

        auto *root = new TreeNode(post[rightpost]);
        auto rootin = rightin;
        while(rootin >= leftin && in[rootin] != post[rightpost]) {
            rootin --;
        }

        auto right = rightin - rootin;
        root->left = post_order(leftin, rootin - 1, leftpost, rightpost - right - 1, in, post);
        root->right = post_order(rootin + 1, rightin, rightpost - right, rightpost - 1, in, post);
        return root;
    }
};
// @lc code=end

