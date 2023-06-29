class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next)return nullptr;
        ListNode*hare=head,*tor=head;
		//we will find the intersecting point of hare and tor
        do{
            hare=hare->next->next;
            tor=tor->next;
        }while(tor!=hare&&hare&&hare->next);
		
		//check if the cycle is there or not
        if(!hare||!hare->next){
            return nullptr;
        }
        else{
		//if present then we will take tor to the head
            tor=head;
			//while they dont meet again we will increment distance by one 
            while(hare!=tor){
                hare=hare->next;
                tor=tor->next;
            }
        }
		//returning the tor
        return tor;
    }
};