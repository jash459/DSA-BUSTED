class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int total = (n * (n + 1)) / 2;
        int sum = nums[0];
        int duplicate = -1;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1])
                duplicate = nums[i];

            sum += nums[i];
        }

        int missing = total - (sum - duplicate);

        return {duplicate, missing};
    }
};
