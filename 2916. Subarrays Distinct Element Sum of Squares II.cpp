class Solution {
    typedef long long ll;
    vector<ll> s, q, lz;
    void app(int o, int len, ll k) {
        q[o] += 2 * k * s[o] + k * k * len;
        s[o] += k * len;
        lz[o] += k;
    }
    void upd(int o, int l, int r, int L, int R) {
        if (L <= l && r <= R) { app(o, r - l + 1, 1); return; }
        int m = (l + r) / 2;
        if (lz[o]) {
            app(2*o, m - l + 1, lz[o]);
            app(2*o+1, r - m, lz[o]);
            lz[o] = 0;
        }
        if (L <= m) upd(2*o, l, m, L, R);
        if (R > m) upd(2*o+1, m+1, r, L, R);
        s[o] = s[2*o] + s[2*o+1];
        q[o] = q[2*o] + q[2*o+1];
    }
public:
    int sumCounts(vector<int>& nums) {
        const ll MOD = 1e9 + 7;
        int n = nums.size();
        s.assign(4*n, 0); q.assign(4*n, 0); lz.assign(4*n, 0);
        vector<int> last(100001, -1);
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            upd(1, 0, n-1, last[nums[i]] + 1, i);
            last[nums[i]] = i;
            ans = (ans + q[1]) % MOD;
        }
        return ans;
    }
};
