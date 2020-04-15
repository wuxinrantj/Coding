#include "../binarytree.h"
#include <iostream>

using namespace std;

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
      if(!root) {
        return new TreeNode(val);
      }

      if (root->val < val) {
        root->right = insertIntoBST(root->right, val);
      } else {
        root->left = insertIntoBST(root->left, val);
      }
      return root;
    }
};

int main() {
    string line = "[4,2,7,1,3]";
    TreeNode* root = stringToTreeNode(line);
    prettyPrintTree(root);
    
    int val = 5;
    Solution so;
    auto ans = so.insertIntoBST(root, val);
    prettyPrintTree(ans);

    return 0;
}


