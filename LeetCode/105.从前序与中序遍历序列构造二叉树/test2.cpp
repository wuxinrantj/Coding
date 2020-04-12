#include "../binarytree.h"
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
//非递归
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {
            return NULL;
        }
        stack<TreeNode*> S;
        auto root = new TreeNode(preorder[0]);

        S.push(root);
        for (int i = 1, j = 0; i < preorder.size(); ++i) {  // i-前序序号，j-中序序号
            TreeNode *back = NULL;
            auto *cur = new TreeNode(preorder[i]);

            while (!S.empty() && S.top()->val == inorder[j]) {
                back = S.top();
                S.pop();
                j++;
            }
            if (back) {
                back->right = cur;
            } else {
                S.top()->left = cur;
            }
            S.push(cur);
        }
        return root;
    }
};

int main() {
    vector<int> preorder{3,9,20,15,7};
    vector<int> inorder{9,3,15,20,7};

    Solution so;
    auto ans = so.buildTree(preorder, inorder);
    prettyPrintTree(ans);
    return 0;
}
