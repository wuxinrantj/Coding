#include "../binarytree.h"
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  int res = 0;

  void dfs(TreeNode* root, int sum){
      sum = 10*sum + root->val;
      if(root->left == NULL && root->right == NULL){
        res += sum;
      }
      if(root->left) dfs(root->left, sum);
      if(root->right) dfs(root->right, sum);
  }

  int sumNumbers(TreeNode* root) {
    if(root == nullptr) {
      return 0;
    }
    
    dfs(root, 0);
    return res;
  }
};


int main() {
  string line = "[4,9,0,5,1]";
  TreeNode* root = stringToTreeNode(line);
  prettyPrintTree(root);

  Solution so;
  auto ans = so.sumNumbers(root);
  cout << ans << endl;

  return 0;
}
