class Solution {
public:
    long long mod= (int)(1000000007);
    int numTilings(int n) {
        int dp[1001];
        
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        
        for (int i=3; i<=n; i++)
            dp[i] = (2*dp[i-1]% mod+ dp[i-3]% mod) % mod;
            
        return dp[n];
    }
};