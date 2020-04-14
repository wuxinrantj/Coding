#include "../binarytree.h"
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;
//自顶向下 用104求深度  
class Solution {
public:
    int height(TreeNode* root) {
      if(!root) {
        return 0;
      }

      return max(height(root->left) + 1, height(root->right) + 1);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) {
          return true;
        } else {
          return abs(height(root->left) - height(root->right)) < 2 && isBalanced(root->left) && isBalanced(root->right);
        }
    }
};

int main() {
    string line = "[1,2,2,3,null,null,3,4,null,null,4]";
    TreeNode* root = stringToTreeNode(line);
    prettyPrintTree(root);

    Solution so;
    auto ans = so.isBalanced(root);
    cout << boolalpha << ans << endl;

    return 0;
}
