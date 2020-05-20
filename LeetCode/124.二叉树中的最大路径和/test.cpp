#include "../binarytree.h"

class Solution {
private:
    int dfs(TreeNode* root, int &val) {
        if (root == nullptr) return 0;
        int left  = max(dfs(root->left,  val), 0);
        int right = max(dfs(root->right, val), 0);

        int lmr = root->val + left + right; 
        val = max(val, lmr);

        return root->val + max(left, right);// 沿着更大的一个分支返回
    }

public:
    int maxPathSum(TreeNode* root) {

        int val = INT_MIN;
        dfs(root, val);
        return val;
    }
};

int main() {
    string line = "[-1,-2,-3,-4,-5]";
    TreeNode* root = stringToTreeNode(line);
    prettyPrintTree(root);
    
    Solution so;
    auto ans = so.maxPathSum(root);
    cout << ans ;
    return 0;
}