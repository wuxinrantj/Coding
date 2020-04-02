
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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
int main(void)
{
	vector<int> a;
	a = { 1,2,null,3,4 };
	TreeNode* t = new TreeNode(a[0]);
	initree(t, a);

	return 0;
}