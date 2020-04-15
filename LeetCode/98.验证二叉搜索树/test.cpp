#include "../binarytree.h"
#include <iostream>


using namespace std;

class Solution {
public:
  bool helper(TreeNode* root, TreeNode* min, TreeNode* max) {
    if(!root) {
      return true;
    }

    if(min != nullptr && root->val <= min->val) return false;
    if(max != nullptr && root->val >= max->val) return false;

    return helper(root->left, min, root) && helper(root->right, root, max);
  }
  bool isValidBST(TreeNode* root) {
    return helper(root, nullptr, nullptr);
  }
};

int main() {
  string line = "[5,1,4,null,null,3,6]";
  TreeNode* root = stringToTreeNode(line);
  prettyPrintTree(root);

  Solution so;
  auto ans = so.isValidBST(root);
  cout << boolalpha << ans << endl;

  return 0;
}
