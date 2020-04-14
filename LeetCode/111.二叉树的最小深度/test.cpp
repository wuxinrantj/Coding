#include "../binarytree.h"
#include <iostream>
#include <algorithm>

using namespace std;
//https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/solution/li-jie-zhe-dao-ti-de-jie-shu-tiao-jian-by-user7208/
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

int main() {
    string line = "[1, 2]";
    TreeNode* root = stringToTreeNode(line);
    prettyPrintTree(root);

    Solution so;
    auto ans = so.minDepth(root);
    cout << ans << endl;

    return 0;
}
