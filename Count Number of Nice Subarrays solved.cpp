



class Solution {
    public :
    int helpMe(vector<int>& nums,int goal){
        int l=0;
        int r=0;
        int sum=0;
        int cnt=0;
        if(goal<0){
            return 0;
        }
        while(r<nums.size()){
            sum += nums[r]%2;        
            while(sum>goal){
                if(nums[l]%2==1){
                    sum--;
                }
                l++;
            }
            cnt=cnt+r-l+1;
            r++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {  
       return helpMe(nums,k)-helpMe(nums,k-1);
    }
};
