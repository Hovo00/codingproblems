 ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast -> next -> next;
            slow = slow -> next;
            if (slow == fast) break;
        }
        if (slow != fast || !slow || !slow->next) return nullptr;
        slow = slow -> next;
        int count = 1;
        while(slow != fast) {
            slow = slow -> next;
            ++count;
        }
        fast = head;
        slow = head;
        for (int i = 0; i < count; ++i) {
            fast = fast -> next;
        }
        while (slow != fast) {
            slow = slow -> next;
            fast = fast -> next;
        }
        return slow;
    }
