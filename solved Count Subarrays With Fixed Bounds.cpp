class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int last_invalid = -1, last_min = -1, last_max = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < minK || nums[i] > maxK) {
                last_invalid = i;
            }
            if (nums[i] == minK) last_min = i;
            if (nums[i] == maxK) last_max = i;
            ans += max(0, min(last_min, last_max) - last_invalid);
        }
        return ans;
    }
};
