class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suf(n);
        suf[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--)
            suf[i] = max(suf[i + 1], nums[i]);        

        int maxSoFar = 0;
        for (int i = 0; i < n; i++) {
            maxSoFar = max(maxSoFar, nums[i]);
            if (maxSoFar - suf[i] <= k)
                return i;
        }

        return -1;
    }
};
