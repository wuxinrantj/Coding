/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (70.66%)
 * Likes:    272
 * Dislikes: 0
 * Total Accepted:    66.7K
 * Total Submissions: 93.9K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]  
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3 
 * 
 * 输出: [3,2,1]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
//当用堆栈来存储节点，必须分清返回根节点时，是从左子树返回的，还从右子树返回的。所以，使用辅助指针q，其指向最近访问过的节点。
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        TreeNode* p = root,*q = NULL;
        while(p || stk.size()){
            if(p) {                  //走到最左边
                stk.push(p);
                p=p->left;
            } else {
                p = stk.top();
                if(p->right && p->right != q) {   //右子树存在，未被访问
                    p = p->right;
                } else {
                    p = stk.top();
                    stk.pop();
                    res.push_back(p->val);
                    q = p;                        //记录最近访问过的节点
                    p = NULL;                     //节点访问完后，重置p指针
                }
            }
        }
        return res;
    }
};
// @lc code=end

