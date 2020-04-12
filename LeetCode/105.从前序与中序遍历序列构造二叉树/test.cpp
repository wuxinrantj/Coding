#include "../binarytree.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//递归
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return pre_order(0, inorder.size() - 1, 0, inorder.size() - 1, preorder, inorder);
    }
    
    TreeNode *pre_order(int leftpre, int rightpre, int leftin, int rightin, vector<int> &pre, vector<int> &in) {
        if (leftpre > rightpre || leftin > rightin) return NULL;

        auto *root = new TreeNode(pre[leftpre]);
        auto rootin = leftin;
        while (rootin <= rightin && in[rootin] != pre[leftpre]) {
          rootin++;
        }

        auto left = rootin - leftin;
        root->left = pre_order(leftpre + 1, leftpre + left, leftin, rootin - 1, pre, in);
        root->right = pre_order(leftpre + left + 1, rightpre, rootin + 1, rightin, pre, in);
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
