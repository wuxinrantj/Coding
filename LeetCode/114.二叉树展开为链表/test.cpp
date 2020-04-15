#include "../binarytree.h"
#include <iostream>
#include <algorithm>

using namespace std;
//递归
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        flatten(root->left);
        flatten(root->right);
        if (root->left != nullptr) {
            auto pre = root->left;
            while (pre->right != nullptr) {
                pre = pre->right;
            }
            pre->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        return;
    }
};
// 采用后序遍历的方式，也就是 左节点-右节点-打印根节点 这个顺序遍历二叉树。
// 当遍历到根节点后，我们对根节点的左右子树做一些调整。

//     1
//    / \
//   2   3
// 将右节点挂到左节点的最右边

//     1
//    / 
//   2   
//    \   
//     3   
// 再将整个左子树挂到根节点的右边，这样就可以将整棵树变成链表结构了。

//     1
//      \
//       2
//        \
//         3

int main() {
    string line = "[1,2,5,3,4,null,6]";
    TreeNode* root = stringToTreeNode(line);
    prettyPrintTree(root);

    Solution so;
    so.flatten(root);
    prettyPrintTree(root);

    return 0;
}