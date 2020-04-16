#include "../list.h"

using namespace std;
//双指针法，pre先走m-1步到达位置m的前驱节点，pre不动，然后令cur等于pre->next也就是位置m的起始节点（不变），将[m+1,n]这段链表由前至后的插入到位置m的前面，也就是pre的后面
//换句话说：我们每次循环就是将cur的next节点插入到pre的后面，这样插了n-m次后，就完成反转了
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        //设置哑节点的好处：在m=1时，我们也有前驱节点，也可以将cur的next节点依次插入到pre的后面
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *pre = dummy;
        //找到m的前驱节点
        for(int i = 1; i < m; ++i) pre = pre->next;
        ListNode *cur = pre->next;
        for(int i = m; i < n; ++i) {//每次循环将nxt节点插入到pre的后面
            ListNode *nxt = cur->next;
            //cur将nxt节点后面的链表连接起来
            cur->next = nxt->next;
            //将nxt插入到pre后面
            nxt->next = pre->next;
            pre->next = nxt;
        }
        return dummy->next;
    }
};



int main() {
    string line = "[1,2,3,4,5]";
    int m = 2;
    int n = 4;
    ListNode* head = stringToListNode(line);
    prettyPrintLinkedList(head);

    Solution so;
    auto ans = so.reverseBetween(head, m, n);
    prettyPrintLinkedList(ans); 
    
    return 0;
}