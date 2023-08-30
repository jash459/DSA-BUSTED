class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long op=0;
        int last=nums.back();
        for(int i=nums.size()-2; i>=0; i--){
            auto [q, r]=div(nums[i], last);//curr=q*last+r
            if (q==0){
                last=r;
            }
            else if (r==0){ //[last, last, ..., last] use (q-1) ops
                op+=(q-1);
            //    cout<<(q-1);
            }
            else{//curr=(q+1)last-(last-r)
                op+=q;
            //    cout<<q;
                last-=(last-r+q)/(q+1);//-=ceil((last-r)/(q+r))
            }
        //    cout<<"->"<<last<<"\n"; 
        }
        return op;
    }
};