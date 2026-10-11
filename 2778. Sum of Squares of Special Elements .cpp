class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int index = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (n % (i + 1) == 0) {
                index += nums[i] * nums[i];
            }
        }
        return index;
    }
};
