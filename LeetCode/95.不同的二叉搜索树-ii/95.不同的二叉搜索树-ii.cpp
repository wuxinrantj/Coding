/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (62.11%)
 * Likes:    353
 * Dislikes: 0
 * Total Accepted:    26.7K
 * Total Submissions: 42.8K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * 解释:
 * 以上的输出对应以下 5 种不同结构的二叉搜索树：
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
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
// 递归
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return helper(1, n);
    }

    vector<TreeNode*> helper(int start, int end) {
        if(start > end) return {nullptr};
        vector<TreeNode*> res;
        for(int i = start; i <= end; i++) {
            auto left = helper(start, i-1);
            auto right = helper(i+1, end);
            for(auto a:left) {
                for(auto b:right) {
                    TreeNode* node = new TreeNode(i);
                    node->left = a;
                    node->right = b;
                    res.push_back(node);
                }
            }
        }
        return res;
    }
};
// @lc code=end

