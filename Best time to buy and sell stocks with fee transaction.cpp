class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
         int n=prices.size();
        // vector<vector<int>>dp(n, vector<int>(2,-1));
        // return f(0,n,prices,1,dp);

        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[n][0]=0;
        dp[n][1]=0;
        int profit=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
        if(buy)
            profit=max((-prices[ind] + dp[ind+1][0]),(0+ dp[ind+1][1]));
        else
            profit=max(((prices[ind]-fee) + dp[ind+1][1]),(0+ dp[ind+1][0]));
        dp[ind][buy]=profit;
            }
        }
         return dp[0][1]=profit;
    }
};