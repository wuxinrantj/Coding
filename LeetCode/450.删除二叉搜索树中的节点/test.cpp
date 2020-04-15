#include "../binarytree.h"
#include <iostream>

using namespace std;

class Solution {
public:
    TreeNode* getmin(TreeNode* node) {    //右子树最小的值在最左边
      while (node->left != nullptr) {
        node = node->left;
      }
      return node;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
      if(!root) {
        return nullptr;
      }

      if(root->val == key) {
        if(root->left == nullptr) return root->right;    //key为叶子结点或者只有一个子节点
        if(root->right == nullptr) return root->left;

        auto minnode = getmin(root->right);             //左右子都存在，找右子树最小的值替换，并删除
        root->val = minnode->val;
        root->right = deleteNode(root->right, minnode->val);
      } else if (root->val < key) {
        root->right = deleteNode(root->right, key);
      } else {
        root->left = deleteNode(root->left, key);
      }

      return root;
    }
};

int main() {
    string line = "[5,3,6,2,4,null,7]";
    TreeNode* root = stringToTreeNode(line);
    prettyPrintTree(root);
    
    int key = 3;
    Solution so;
    auto ans = so.deleteNode(root, key);
    prettyPrintTree(ans);

    return 0;
}


