#include "../binarytree.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode *> q;
        auto rev = 0;
        if (root) {
            q.push(root);
        }
        
        while (!q.empty()) {
            int count = q.size();
            while(count--) {
                auto front = q.front();
                q.pop();

                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
            }
            rev ++;
        }
        return rev;
    }
};

int main() {
    string line = "[3,9,20,null,null,15,7]";
    TreeNode* root = stringToTreeNode(line);
    prettyPrintTree(root);

    Solution so;
    auto ans = so.maxDepth(root);
    cout << ans << endl;

    return 0;
}
