class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long perimeter = 0, sides = n;
        for(auto it: nums) perimeter += it;
        for(int i=n-1; i>=2; i--){
            if(perimeter <= 2*nums[i]){
                perimeter -= nums[i];
                sides--;
            }
            else break;
        } 
        if(sides == 2) return -1;
        return perimeter;
    }
};
