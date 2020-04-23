#include "../binarytree.h"
//递归
class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr) return 0;
        return count(root, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    int count(TreeNode* node, int sum) {
        if (node == nullptr) return 0;
        return (node->val == sum) + count(node->left, sum - node->val) + count(node->right, sum - node->val);
    }
    
};

int main() {
    string line = "[10,5,-3,3,2,null,11,3,-2,null,1]";
    int sum = 8;
    TreeNode* root = stringToTreeNode(line);
    prettyPrintTree(root);

    Solution so;
    auto ans = so.pathSum(root, sum);
    cout << ans << endl;

    return 0;
}