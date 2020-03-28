
#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
}node;

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
        {
            return l2;
        }
        if (l2 == NULL)
        {
            return l1;
        }
        if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

ListNode* create(vector<int>& data)
{
	ListNode* pHead = NULL;
	ListNode* pPre = NULL;
	for (int i = 0; i < data.size(); i++)
	{
		ListNode* pNode = new ListNode();
		pNode->val = data[i];
		pNode->next = NULL;
		if (pHead == NULL)
			pHead = pNode;
		else
			pPre->next = pNode;
		pPre = pNode;
	}
	return pHead;
}

void print(ListNode* pHead)
{
	ListNode* pNode = pHead;
	while (pNode != NULL){
		cout << pNode->val;
		pNode = pNode->next;
	}
	cout << endl;
}

int main(void)
{
	vector<int> a{1, 2, 4};
	ListNode* l1 = create(a);
    vector<int> b{1, 3, 4};
	ListNode* l2 = create(b);
    ListNode* ans = NULL;

    Solution so;
    ans = so.mergeTwoLists(l1, l2);
    print(ans);
	delete(l1);
	delete(l2);
	delete(ans);

	return 0;
}