#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0;

        vector<int> leftMax(n, 0), rightMax(n, 0);
        leftMax[0] = nums[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], nums[i]);
        }

        rightMax[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], nums[i]);
        }

        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            int left = leftMax[i - 1];
            int right = rightMax[i + 1];
            ans = max(ans, (left - nums[i]) * right);
        }

        return ans;
    }
};
