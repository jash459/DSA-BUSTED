class Solution {
    static inline int S[201];
    static inline int vers = 0;
public:
    bool isGood(vector<int>& nums) {
        vers++;
        int n = nums.size() - 1;
        for (auto& num : nums) {
            if (num > n || S[num] == -vers)
                return false;

            if (S[num] == vers) {
                if (num < n) return false;
                S[num] = -vers;
                continue;
            }
            
            S[num] = vers;
        }
        
        return true;
    }
};
