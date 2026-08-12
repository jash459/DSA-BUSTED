class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int low = 0, high = 1, sol = 1, n = nums.size();
        unordered_map<int, int> mp;

        mp[nums[0]]++;

        while (high < n) {
            mp[nums[high]]++;

            while (mp[nums[high]] > k) {
                mp[nums[low]]--;
                low++;
            }

            sol = max(high - low + 1, sol);
            high++;
        }

        return sol;
    }
};
