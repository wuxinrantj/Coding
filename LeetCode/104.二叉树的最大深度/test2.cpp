#include "../binarytree.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
//递归
class Solution {
 public:
  int maxDepth(TreeNode* root) {
    if (!root) {
      return 0;
    }

    return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
  }
};

int main() {
    string line = "[3,9,20,null,null,15,7]";
    TreeNode* root = stringToTreeNode(line);
    prettyPrintTree(root);

    Solution so;
    auto ans = so.maxDepth(root);
    cout << ans << endl;

    return 0;
}
