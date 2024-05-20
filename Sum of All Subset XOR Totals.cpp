class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return helper(nums, 0, 0); 
    }

private:
    int helper(vector<int>& nums, int level, int currentXOR) {
        if (level == nums.size()) return currentXOR;
        int include = helper(nums, level + 1, currentXOR ^ nums[level]);
        int exclude = helper(nums, level + 1, currentXOR);
        return include + exclude;
    }
};
