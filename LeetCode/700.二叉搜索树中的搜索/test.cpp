#include "../binarytree.h"
#include <iostream>

using namespace std;

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) {
          return nullptr;
        }

        if(root->val == val) {
          return root;
        } else if (root->val < val) {
          return searchBST(root->right, val);
        } else {
          return searchBST(root->left, val);
        }
        
    }
};

int main() {
    string line = "[4,2,7,1,3]";
    TreeNode* root = stringToTreeNode(line);
    prettyPrintTree(root);
    
    int val = 2;
    Solution so;
    auto ans = so.searchBST(root, val);
    prettyPrintTree(ans);

    return 0;
}


