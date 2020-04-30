#include "../list.h"

using namespace std;

class Solution {
public:
    ListNode* merge(ListNode* p1, ListNode* p2){   //21. 合并两个
        if(!p1) return p2;
        if(!p2) return p1;
        if(p1->val <= p2->val){
            p1->next = merge(p1->next, p2);
            return p1;
        } else {
            p2->next = merge(p1, p2->next);
            return p2;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) return nullptr;
        ListNode* head = lists[0];
        for(int i = 1; i < lists.size(); ++i){
            if(lists[i]) head = merge(head, lists[i]);
        }
        return head;  
    }
};


int main() {
    vector<ListNode*> lists;
    string line1 = "[1,4,5]";
    ListNode* head1 = stringToListNode(line1);
    lists.push_back(head1);
    string line2 = "[1,3,4]";
    ListNode* head2 = stringToListNode(line2);
    lists.push_back(head2);
    string line3 = "[2,6]";
    ListNode* head3 = stringToListNode(line3);
    lists.push_back(head3);

    Solution so;
    auto ans = so.mergeKLists(lists);
    prettyPrintLinkedList(ans); 
    
    return 0;
}