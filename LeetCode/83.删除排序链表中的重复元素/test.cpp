
#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
}node;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto curr = head;

        while (curr && curr->next) {
        if (curr->val == curr->next->val) {
            auto temp = curr->next;
            curr->next = temp->next;

            delete temp;
            temp = nullptr;
        } else {
            curr = curr->next;
        }
        }

        return head;
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
	vector<int> a{1, 2, 2, 4};
	ListNode* head = create(a);
    ListNode* ans = NULL;

    Solution so;
    ans = so.deleteDuplicates(head);
    print(ans);
	delete(head);
	delete(ans);

	return 0;
}
