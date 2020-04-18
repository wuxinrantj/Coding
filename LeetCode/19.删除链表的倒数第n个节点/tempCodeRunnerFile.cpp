        ListNode* fast{head};
        ListNode* slow{head};
        ListNode* dummy = new ListNode(0);  //哑节点
        dummy->next = head;
        while(n-- > 0) {
            fast = fast->next;
        }
        while(fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;

        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};