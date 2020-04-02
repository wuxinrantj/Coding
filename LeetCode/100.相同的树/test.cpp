
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//广度优先迭代建立二叉树
#define null 9999
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* initree(TreeNode* root, vector<int>& in) {//root进行了初始化
	vector<int>::iterator ptr = in.begin() + 1;
	queue<TreeNode*> s;
	s.push(root);
	int cnt = 1;
	while (ptr != in.end()) {
		TreeNode* temp = s.front();
		s.pop();
		if (cnt == in.size())
			break;
		if (*ptr != 9999) {
			temp->left = new TreeNode(*ptr++);
			cnt++;
			s.push(temp->left);
		}
		else {
			ptr++;
			cnt++;
		}
		if (cnt == in.size())
			break;
		if (*ptr != 9999) {
			temp->right = new TreeNode(*ptr++);
			cnt++;
			s.push(temp->right);
		}
		else {
			ptr++;
			cnt++;
		}
		if (cnt == in.size())
			break;
	}
	return root;
}

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) {
			return true;
		}
		if(p != NULL && q != NULL && p->val == q->val) {
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		}
		return false;
    }
};


int main(void)
{
	vector<int> a;
	a = { 1,2 };
	TreeNode* ta = new TreeNode(a[0]);
	initree(ta, a);

	vector<int> b;
	b = { 1,null,2 };
	TreeNode* tb = new TreeNode(b[0]);
	initree(tb, b);

	bool ans;
    Solution so;
    ans = so.isSameTree(ta, tb);
    cout << boolalpha << ans << endl;

    return 0;
}
