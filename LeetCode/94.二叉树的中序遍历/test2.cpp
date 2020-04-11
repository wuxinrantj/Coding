#include "../binarytree.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
//迭代
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        auto p = root;
        while(p || stk.size()){
            while(p){
                stk.push(p);
                p = p->left;
            }
            p = stk.top();
            stk.pop();
            res.push_back(p->val);
            p = p->right;
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
