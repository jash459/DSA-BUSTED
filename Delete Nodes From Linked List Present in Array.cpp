class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> hasN(nums.begin(), nums.end());
        ListNode dummy(0, head);
        ListNode* prev=&dummy, *tmp=NULL;
        for(ListNode* curr=head; curr; curr=curr->next, delete tmp){
            if (hasN.count(curr->val)){ 
                prev->next = curr->next;
                tmp=curr;
            }
            else{
                prev = prev->next;
                tmp=NULL;
            }
        }
        return dummy.next;
    }
};
