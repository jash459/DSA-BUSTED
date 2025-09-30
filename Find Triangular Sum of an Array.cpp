class Solution {
public:
    int triangularSum(vector<int>& nums) {
       int n=nums.size();
       for (int i=n-1; i>=1; i--){
           vector<int> a(i, 0);
           for(int j=0; j<i; j++){
               a[j]=(nums[j]+nums[j+1])%10;
           }
           nums=a;
       }
       return nums[0]; 
    }
};
