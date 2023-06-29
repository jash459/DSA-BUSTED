class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>&lists) 
    {
        //instead of checking everytime k lists and appending minimum of all to our answer list, maintain priority queue which gives us the minimum element in O(1) instead of O(K), where K is number of lists.
        //Sure O(logN) time would be required to insert and delete but its far off better than linear time
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap;//value,index of ListNode in vector
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]!=NULL)
            {
                minheap.push({lists[i]->val,i});
            }
        }
        if(minheap.empty())//Edge Case Handling
        {
            return NULL;
        }
        ListNode* node=new ListNode();
        ListNode* head=node;//store the head of ans
        while(1)
        {
            pair<int,int>x=minheap.top();
            minheap.pop();
            node->val=x.first;
            if(lists[x.second]->next!=NULL)//check if end of list not reached
            {
                lists[x.second]=lists[x.second]->next;//traverse list further
                minheap.push({lists[x.second]->val,x.second});//push value of current pointer at this list
            }
            if(!minheap.empty())//still elements exist to insert in list
            {
                node->next=new ListNode();
                node=node->next;
            }
            else//all elements inserted and lists traversed
            {
                break;
            }
        }
        return head;
    }
};