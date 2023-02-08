
class Solution {
public:

    int jump(vector<int>& nums) {

      for(int i = 1; i < nums.size(); i++)
      {
        nums[i] = max(nums[i] + i, nums[i-1]);
      }

      int ind = 0;
      int result = 0;

      while(ind < nums.size() - 1)
      {
        result++;
        ind = nums[ind];
      }

      return result;
    }
};
