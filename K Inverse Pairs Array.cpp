class Solution {
public:
    int kInversePairs(int n, int k) {
        int dp[1001][1001] = {1};  
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                for (int k = 0; k <= min(j, i - 1); k++) {
                    if (j - k >= 0) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % 1000000007;
                    }
                }
            }
        }
        return dp[n][k];
    }
};


