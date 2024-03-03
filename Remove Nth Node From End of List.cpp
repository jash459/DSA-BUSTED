class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        if (fast == NULL) {
            ListNode* newHead=head->next;
            delete head; 
            return newHead;
        }
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *node= slow->next;
        slow->next = slow->next->next;
        delete node;
        return head;
    }
};
