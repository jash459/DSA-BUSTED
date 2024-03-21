class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* l1 = NULL;
        ListNode* l2 = reverseList(head->next);
        head->next->next = head;
        head->next=l1;
        return l2;
    }
};
