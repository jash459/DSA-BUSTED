class Solution {
public:
    int tupleSameProduct(vector<int>& x) {
        unordered_map<int, int>mp;
        int n = x.size() ,ans = 0;

        for(int i = 0; i < n - 1; i++)
            for(int j = i + 1; j < n ;j++)
                mp[x[i] * x[j]]++;

        for(auto [a, b] : mp)
            ans += b * (b - 1) / 2 * 8;

        return ans;
    }
};
