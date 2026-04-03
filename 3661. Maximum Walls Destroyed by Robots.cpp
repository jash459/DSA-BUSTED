class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        vector<pair<int, int>> r(n);
        unordered_set<int> rs;
        
        for(int i = 0; i < n; i++) {
            r[i] = {robots[i], distance[i]};
            rs.insert(robots[i]);
        }
        sort(r.begin(), r.end());
        
        int bw = 0;
        vector<int> vw;
        for(int w : walls) {
            if(rs.count(w)) bw++;
            else vw.push_back(w);
        }
        sort(vw.begin(), vw.end());
        
        auto get_w = [&](int x, int y) {
            if(x > y) return 0;
            auto i1 = lower_bound(vw.begin(), vw.end(), x);
            auto i2 = upper_bound(vw.begin(), vw.end(), y);
            return (int)(i2 - i1);
        };
        
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = get_w(r[0].first - r[0].second, r[0].first - 1);
        dp[0][1] = 0;
        
        for(int i = 1; i < n; i++) {
            int L = r[i-1].first, R = r[i].first;
            int d1 = r[i-1].second, d2 = r[i].second;
            
            int eR = min(R - 1, L + d1);
            int sL = max(L + 1, R - d2);
            
            int wR = get_w(L + 1, eR);
            int wL = get_w(sL, R - 1);
            int wBoth = (eR >= sL) ? get_w(L + 1, R - 1) : wR + wL;
            
            dp[i][0] = max(dp[i-1][0] + wL, dp[i-1][1] + wBoth);
            dp[i][1] = max(dp[i-1][0], dp[i-1][1] + wR);
        }
        
        int wEnd = get_w(r[n-1].first + 1, r[n-1].first + r[n-1].second);
        int ans = max(dp[n-1][0], dp[n-1][1] + wEnd);
        
        return ans + bw;
    }
};
