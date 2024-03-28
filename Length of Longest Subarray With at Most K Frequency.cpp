class Solution {
public:
    int maxSubarrayLength(vector<int>& v, int k) {
        int n = v.size(), cnt = 0, ans = 0, start = 0, end = 0;
        unordered_map<int, int> mpp;
        while(end < n) {
            mpp[v[end++]] += 1;
            while(mpp[v[end - 1]] > k) {
                mpp[v[start++]] -= 1;
            }
            ans = max(ans, end - start);
        }
        return ans;
    }
};
