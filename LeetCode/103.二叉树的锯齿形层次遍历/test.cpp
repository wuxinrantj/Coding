#include "../binarytree.h"
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode *> q;
        vector<vector<int>> res;
        auto rev = 0;
        if (root) {
            q.push(root);
        }
        
        while (!q.empty()) {
            vector<int> level;
            int count = q.size();
            while(count--) {
                auto front = q.front();
                q.pop();

                level.push_back(front->val);

                if (front->left) {
                    q.push(front->left);
                }
                if (front->right) {
                    q.push(front->right);
                }
            }
            if(rev % 2 == 1) {
                reverse(level.begin(), level.end());
            }
            rev ++;
            res.push_back(level);
        }
        return res;
    }
};

int main() {
    string line = "[3,9,20,null,null,15,7]";
    TreeNode* root = stringToTreeNode(line);
    prettyPrintTree(root);

    Solution so;
    auto ans = so.zigzagLevelOrder(root);
    for(int i = 0; i < ans.size(); ++i) {
        for(int j = 0; j < ans[i].size(); ++j) {
            cout << ans[i][j] << ',';
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}
