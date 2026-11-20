#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
         int n = nums.size();
         sort(nums.begin(), nums.end());
         int d0 = 1;
         int d1 = 1;
         int ans = 1;
         int prev_val = nums[0];
         for (int i = 1; i < n; ++i) {
             int cur_val = nums[i];
             int diff = cur_val - prev_val;
             prev_val = cur_val;
             if (diff == 0) {
                   d1 = d0 + 1;
       }
             else if (diff == 1) {
                    d0 += 1;
                    d1 += 1;
       }
             else if (diff == 2) {
                    d0 = d1 + 1;
                    d1 = 1;
       }
              else {
                    d0 = 1;
                    d1 = 1;
       }

          if (d0 > ans) {
             ans = d0;
       }

          if (d1 > ans) {
             ans = d1;
   }
}

          return ans;
  }
};
