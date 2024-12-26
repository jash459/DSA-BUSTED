class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
         int n=nums.size();
    int totSum = 0;
    for(int i=0; i<n;i++){
        totSum += nums[i];
    }
    //Checking for edge cases
    if(totSum-target <0 || (totSum-target)%2 ) return 0;
    int tar=((totSum-target)/2);
    vector<vector<int>> dp(n,vector<int>(tar+1,0));
    if(nums[0] == 0) dp[0][0] =2;  // 2 cases -pick and not pick
    else dp[0][0] = 1;  // 1 case - not pick
    if(nums[0]!=0 && nums[0]<=tar) dp[0][nums[0]] = 1;  // 1 case -pick
    for(int ind = 1; ind<n; ind++){
        for(int target= 0; target<=tar; target++){
            int notTaken = dp[ind-1][target];
            int taken = 0;
            if(nums[ind]<=target) taken = dp[ind-1][target-nums[ind]];
            dp[ind][target]= (notTaken + taken);
        }
    }
    return dp[n-1][tar];
    }
};
