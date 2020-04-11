#include "../binarytree.h"
#include <iostream>
#include <vector>

using namespace std;
//递归
class Solution {
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        if (root != NULL) {
            inorderTraversal(root->left);
            res.push_back(root->val);
            inorderTraversal(root->right);
        }
        return res;
    }
};

int main() {
    string line = "[1,null,2,3]";
    TreeNode* root = stringToTreeNode(line);
    prettyPrintTree(root);

    Solution so;
    auto ans = so.inorderTraversal(root);
    for(auto v : ans) {
        cout << v << ',';
    }
    cout << endl;

    return 0;
}
