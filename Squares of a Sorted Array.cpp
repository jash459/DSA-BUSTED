class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
     int n = nums.size();
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {   // Square each element in 'nums'.
        nums[i] *= nums[i]; 
    }
    int i=nums.size()-1;  //initial position of i 
    int l = 0, r = nums.size()-1;
 // Use two pointers to merge sorted squares in non-decreasing order.
    while (l <= r) {
        if (nums[l] > nums[r]) {   
            ans[i--] = nums[l++];
        } else {
            ans[i--] = nums[r--];
        }
    }

    return ans;
}
};
