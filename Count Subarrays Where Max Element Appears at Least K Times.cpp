class Solution {
public:
        return a + b + a * b + 1;
    }
    
    long long countSubarrays(vector<int>& nums, int k) {
        int maxnum = *max_element(begin(nums), end(nums));
        long long ans = 0;
        int n = nums.size();
        vector<int> maxind;
        for (int i = 0; i < n; i++) {
            if (nums[i] == maxnum) {
                maxind.push_back(i);
            }
        }

        int indsize = maxind.size();
        
        for (int i = 0; i <= indsize - k; i++) {
            
            int end = i + k - 1;
            long long a, b;             if (i == 0) {
                
                a = maxind[i];
            } else {
                
                a = maxind[i] - maxind[i - 1] - 1;

            b = n - 1 - maxind[end];
          
            ans += subarr(a, b);
        }
        return ans;
    }
};
