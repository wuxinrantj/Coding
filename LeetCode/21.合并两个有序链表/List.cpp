
#include <iostream>
#include <vector>
using namespace std;
 
struct ListNode{
	int value;
	ListNode* next;
}node;
ListNode* create(vector<int>& data)
{
	ListNode* pHead = NULL;
	ListNode* pPre = NULL;
	for (int i = 0; i < data.size(); i++)
	{
		ListNode* pNode = new ListNode();
		pNode->value = data[i];
		pNode->next = NULL;
		if (pHead == NULL)
			pHead = pNode;
		else
			pPre->next = pNode;
		pPre = pNode;
	}
	return pHead;
}
 
int length(ListNode* pHead)
{
	ListNode* pNode = pHead;
	if (pHead == NULL)
		return 0;
	int len = 0;
	while (pNode != NULL)
	{
		++len;
		pNode = pNode->next;
	}
	return len;
}
 
void print(ListNode* pHead)
{
	ListNode* pNode = pHead;
	while (pNode != NULL){
		cout << pNode->value;
		pNode = pNode->next;
	}
	cout << endl;
}
//单链表的删除
ListNode* del(ListNode* pHead, int num)
{
	ListNode* pNode = pHead;
	ListNode* pTemp = NULL;
	while (num != pNode->value && pNode->next != NULL)
	{
		pTemp = pNode;
		pNode = pNode->next;
	}
	if (pNode->value == num)
	{
		if (pNode == pHead)
		{
			pHead = pNode->next;
			free(pNode);
		}
		else
		{
			pTemp->next = pNode->next;
			free(pNode);
		}
	}
	return pHead;
}
 
//单链表的插入
ListNode* Insert(ListNode* pHead, int num)
{
	ListNode* pNode = pHead;
	ListNode* pTemp = NULL;
	ListNode* pNew = (ListNode*)malloc(sizeof(ListNode));
	pNew->value = num;
	while (pNew->value > pNode->value && pNode->next != NULL)
	{
		pTemp = pNode;
		pNode = pNode->next;
	}
	if (pNew->value <= pNode->value)
	{
		if (pHead == pNode)
		{
			pNew->next = pNode;
			pHead = pNew;
		}
		else
		{
			pTemp->next = pNew;
			pNew->next = pNode;
		}
	}
	else
	{
		pNode->next = pNew;
		pNew->next = NULL;
	}
	return pHead;
}
 
//单链表的排序
ListNode* sort(ListNode* pHead)
{
	int temp = 0;
	int len = length(pHead);
	if (pHead == NULL || pHead->next == NULL)
		return pHead;
	ListNode* pNode = pHead;
	for (int i = 1; i < len; i++)
	{
		pNode = pHead;
		for (int j = 0; j < len - i; j++)
		{
			if (pNode->value > pNode->next->value)
			{
				temp = pNode->value;
				pNode->value = pNode->next->value;
				pNode->next->value = temp;
			}
			pNode = pNode->next;
		}
	}
	return pHead;
}
 
int main(void)
{
	vector<int> a{1, 2, 4};
	ListNode* pHead = create(a);
	print(pHead);
    vector<int> b{1, 3, 4};
	ListNode* pHead2 = create(b);
    print(pHead2);
	return 0;
}