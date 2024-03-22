class Solution {
public:
    ListNode* front;
    bool check(ListNode* Node){
        if (Node!=NULL) {
            if (!check(Node->next)) return 0;
        //    cout<<"("<<Node->val<<","<<front->val<<")";
            if (Node->val!=front->val) return 0;
            front=front->next;
        }
        return 1;
    }
    bool isPalindrome(ListNode* head) {
        front=head;
        return check(head);
    }
};
