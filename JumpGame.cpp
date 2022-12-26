class Solution {
public:
   bool canJump(vector<int>& nums) 
{
    int maxjump = 0;
    
    for (int i = 0; i < nums.size(); i++)
    {
        maxjump = max(nums[i] + i, maxjump);
        if (maxjump < i + 1)
            break;
    }
    
    return maxjump >= nums.size() - 1;
}
};