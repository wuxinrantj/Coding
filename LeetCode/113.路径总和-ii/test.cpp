#include "../binarytree.h"
#include <iostream>
#include <algorithm>

using namespace std;
//递归
class Solution {
public:
    vector<vector<int>> res;

    void dfs(TreeNode* root, int sum, vector<int> temp){
        temp.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            int s = 0;
            for(auto n: temp) {
              s += n;
            }
            if(s == sum) res.push_back(temp);
        }
        if(root->left) dfs(root->left, sum, temp);
        if(root->right) dfs(root->right, sum, temp);
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
      if(root == nullptr) {
        return res;
      }
      dfs(root, sum, {});
      return res;
    }
};

int main() {
    string line = "[5,4,8,11,null,13,4,7,2,null,null,5,1]";
    TreeNode* root = stringToTreeNode(line);
    prettyPrintTree(root);
    int sum = 22;

    Solution so;
    auto ans = so.pathSum(root, sum);
    for(int i = 0; i < ans.size(); ++i) {
      for(int j = 0; j < ans[i].size(); ++j) {
        cout << ans[i][j] << ',';
      }
      cout << endl;
    }

    return 0;
}
