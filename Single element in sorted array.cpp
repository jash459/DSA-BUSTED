class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid_ele = (left + right) / 2;
            if (mid_ele % 2 == 1) {
                mid_ele--;
            }
            if (nums[mid_ele] != nums[mid_ele + 1]) {
                right = mid_ele;
            } else {
                left = mid_ele + 2;
            }
        }
        return nums[left];
    }
};