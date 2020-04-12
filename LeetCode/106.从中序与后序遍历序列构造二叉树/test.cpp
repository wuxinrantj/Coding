#include "../binarytree.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//递归
// class Solution {
// public:
//     TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//         return pre_order(0, inorder.size() - 1, 0, inorder.size() - 1, preorder, inorder);
//     }
    
//     TreeNode *pre_order(int leftpre, int rightpre, int leftin, int rightin, vector<int> &pre, vector<int> &in) {
//         if (leftpre > rightpre || leftin > rightin) return NULL;

//         auto *root = new TreeNode(pre[leftpre]);
//         auto rootin = leftin;
//         while (rootin <= rightin && in[rootin] != pre[leftpre]) {
//           rootin++;
//         }

//         auto left = rootin - leftin;
//         root->left = pre_order(leftpre + 1, leftpre + left, leftin, rootin - 1, pre, in);
//         root->right = pre_order(leftpre + left + 1, rightpre, rootin + 1, rightin, pre, in);
//         return root;
//     }
// };
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return post_order(0, inorder.size() - 1, 0, inorder.size() - 1, inorder, postorder);
    }

    TreeNode *post_order(int leftin, int rightin, int leftpost, int rightpost, vector<int> &in, vector<int> &post) {
        if(leftin > rightin || leftpost > rightpost) return NULL;

        auto *root = new TreeNode(post[rightpost]);
        auto rootin = rightin;
        while(rootin >= leftin && in[rootin] != post[rightpost]) {
            rootin --;
        }

        auto right = rightin - rootin;
        root->left = post_order(leftin, rootin - 1, leftpost, rightpost - right - 1, in, post);
        root->right = post_order(rootin + 1, rightin, rightpost - right, rightpost - 1, in, post);
        return root;
    }
};

int main() {
    vector<int> postorder{9,15,7,20,3};
    vector<int> inorder{9,3,15,20,7};

    Solution so;
    auto ans = so.buildTree(inorder, postorder);
    prettyPrintTree(ans);
    return 0;
}
