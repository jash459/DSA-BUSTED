class Solution
{
    public:
    
    // Tabulation gives me TLE
    
    // int f(vector<int> &nums){
    //     int n=nums.size();
    //     vector<int> dp(n,-1);
        
    //     dp[0]=nums[0];
    //     for(int i=1;i<n;i++){
    //         int pick=nums[i];
    //         if(i>1) pick+=dp[i-2];
    //         int nonpick=dp[i-1];
    //         dp[i]=max(pick,nonpick);
    //     }
    //     return dp[n-1];
    // }
    
    // Space optimzation
    
        // int f(vector<int> &nums){
        // int n=nums.size();
        
        // int prev=nums[0];
        // int prev2=0;
    
        // for(int i=1;i<n;i++){
        //     int pick=nums[i];
        //     if(i>1) pick+=prev2;
        //     int nonpick=prev;
        //     int curr =max(pick,nonpick);
            
        //     prev2=prev;
        //     prev=curr;
        // }
        // return prev;
    
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        // if(n==1) return arr[0];
        // vector<int> temp1, temp2;
        // for(int i=0;i<n;i++){
        //     if(i!=0) temp1.push_back(arr[i]);
        //     if(i!=(n-1)) temp2.push_back(arr[i]);
        // }
        
        // int ans1=f(temp1);
        // int ans2=f(temp2);
        
        // return max(ans1,ans2);
         int secondLastPrev = 0;
        int lastPrev = arr[0];
        int crr = 0;
        
        for(int i = 1; i < n; i++){
            
            int pick = arr[i];
            if(i > 1) pick += secondLastPrev;
            int notPick = 0 + lastPrev;
            
            int crr = max(pick, notPick);
            
            secondLastPrev = lastPrev;
            lastPrev = crr;
        }
        return lastPrev;
    }
};