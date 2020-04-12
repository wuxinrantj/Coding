#include "../binarytree.h"
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
//当用堆栈来存储节点，必须分清返回根节点时，是从左子树返回的，还从右子树返回的。所以，使用辅助指针q，其指向最近访问过的节点。
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> res;
        TreeNode* p = root,*q = NULL;
        while(p || stk.size()){
            if(p) {                  //走到最左边
                stk.push(p);
                p=p->left;
            } else {
                p = stk.top();
                if(p->right && p->right != q) {   //右子树存在，未被访问
                    p = p->right;
                } else {
                    p = stk.top();
                    stk.pop();
                    res.push_back(p->val);
                    q = p;                        //记录最近访问过的节点
                    p = NULL;                     //节点访问完后，重置p指针
                }
            }
        }
        return res;
    }
};

int main() {
    string line = "[1,null,2,3]";
    TreeNode* root = stringToTreeNode(line);
    prettyPrintTree(root);

    Solution so;
    auto ans = so.postorderTraversal(root);
    for(auto v : ans) {
        cout << v << ',';
    }
    cout << endl;

    return 0;
}
