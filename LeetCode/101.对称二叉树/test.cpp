
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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) {
			return true;
		} else {
			return ChildSymmetric(root->left, root->right);
		}
    }

public:
    bool ChildSymmetric(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) {
			return true;
		}
		if(p != NULL && q != NULL && p->val == q->val) {
			return ChildSymmetric(p->left, q->right) && ChildSymmetric(p->right, q->left);
		}
		return false;
    }
};

int main(void)
{
	vector<int> a;
	a = { 1,2,2,null,3,null,3 };
	TreeNode* root = new TreeNode(a[0]);
	initree(root, a);

	bool ans;
    Solution so;
    ans = so.isSymmetric(root);
    cout << boolalpha << ans << endl;

    return 0;
}
