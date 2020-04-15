#include "../binarytree.h"
#include <iostream>
#include <algorithm>

using namespace std;
//非递归
class Solution {
public:
    void flatten(TreeNode* root) {
        while (root != nullptr) {
            if (root->left != nullptr) {
                auto most_right = root->left; // 如果左子树不为空, 那么就先找到左子树的最右节点
                while (most_right->right != nullptr) most_right = most_right->right; // 找最右节点
                most_right->right = root->right; // 然后将根的右孩子放到最右节点的右子树上
                root->right = root->left; // 这时候根的右孩子可以释放, 令左孩子放到右孩子上
                root->left = nullptr; // 将左孩子置为空
            }
            root = root->right; // 继续下一个节点
        }
        return;
    }
};

int main() {
    string line = "[1,2,5,3,4,null,6]";
    TreeNode* root = stringToTreeNode(line);
    prettyPrintTree(root);

    Solution so;
    so.flatten(root);
    prettyPrintTree(root);

    return 0;
}