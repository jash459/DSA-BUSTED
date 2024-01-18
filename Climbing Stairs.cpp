class Solution {
public:
    int climbStairs(int n) {
        // Simplar to fibonacii: 
// Memorization

//     int climbStairs(int n) {
//       vector<int>dp(n+1,-1);
//       cout<<climbStairswithjash(n,dp);
//     }
  
//     int climbStairswithjash(int n ,vector<int>&dp){
//     if(n==1 || n==2) return n;
//     if(dp[n]!=-1) return dp[n];
//     return dp[n]=climbStairswithjash(n-1,dp)  + climbStairswithjash(n-2,dp);
//   }
  
  
// Tablution: 
// int climbStairswithjash(int n ,vector<int>&dp){
//     int dp[1]=1, dp[1]=2;
//     for(int i=3;i<=n;i++){
//       dp[i]=dp[i-1]+dp[i-2];
//     }
//     return dp[n];
//   }
  
// Space optimzation
int prev2=1;
int prev=1;
if(n==0) return prev2;
if(n==1) return prev;
for(int i=2;i<=n;i++){
  int curr=prev+prev2;
  prev2=prev;
  prev=curr; 
}
return prev;
    }
};
