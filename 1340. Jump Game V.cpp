class Solution {
public:
    
    int dfs(int idx, vector<int>& arr, int d, vector<int>& dp) {
        
        if(dp[idx] != -1)
            return dp[idx];

        int ans = 1;

        for(int i = idx - 1; i >= max(0, idx - d); i--) {

            if(arr[i] >= arr[idx])
                break;

            ans = max(ans, 1 + dfs(i, arr, d, dp));
        }

        for(int i = idx + 1; i <= min((int)arr.size() - 1, idx + d); i++) {

            if(arr[i] >= arr[idx])
                break;

            ans = max(ans, 1 + dfs(i, arr, d, dp));
        }

        return dp[idx] = ans;
    }

    
    int maxJumps(vector<int>& arr, int d) {

        int n = arr.size();

        vector<int> dp(n, -1);

        int result = 1;

        for(int i = 0; i < n; i++) {
            result = max(result, dfs(i, arr, d, dp));
        }

        return result;
    }
};
