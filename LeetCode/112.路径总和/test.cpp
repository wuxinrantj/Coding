#include "../binarytree.h"
#include <iostream>
#include <algorithm>

using namespace std;
//递归
class Solution {
public:
  bool hasPathSum(TreeNode* root, int sum) {
    if(!root) {
      return false;
    }

    sum -= root->val;
    if (root->left == nullptr && root->right == nullptr && sum == 0) {  //到叶子节点
      return true;
    }

    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
    }
};

int main() {
    string line = "[5,4,8,11,null,13,4,7,2,null,null,null,1]";
    TreeNode* root = stringToTreeNode(line);
    prettyPrintTree(root);
    int sum = 22;

    Solution so;
    auto ans = so.hasPathSum(root, sum);
    cout << boolalpha << ans << endl;

    return 0;
}
