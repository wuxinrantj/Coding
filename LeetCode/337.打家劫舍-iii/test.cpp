#include "../binarytree.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(TreeNode* root) {
        auto res = dp(root);
        return max(res[0], res[1]);
    }

    vector<int> dp(TreeNode* root) {    //返回一个大小为2的数组，0位表示不抢，1位表示抢
        if(root == NULL) {
            return {0,0};
        }
        vector<int> left = dp(root->left);
        vector<int> right = dp(root->right);
        //抢
        int rob = root->val + left[0] + right[0];
        //不抢
        int not_rob = max(left[0], left[1]) + max(right[0], right[1]);

        return {not_rob, rob};
    }
};

int main() {
    string line = "[3,4,5,1,3,null,1]";
    TreeNode* root = stringToTreeNode(line);
    prettyPrintTree(root);

    Solution so;
    auto ans = so.rob(root);
    cout << ans << endl;

    return 0;
}
