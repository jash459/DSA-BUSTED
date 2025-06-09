class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1; 
        k--; 
        while (k > 0) {
            long long steps = count_steps(n, curr, curr+1); 
            if (steps <= k) {
                curr += 1; 
                k -= steps;
            } else {
                curr *= 10; 
                k -= 1;
            }
        }
        return curr;
    }
    long long count_steps(int n, long long curr, long long next) {
        long long steps = 0; 

        while (curr <= n) {
            steps += min(n + 1LL, next) - curr;
            curr *= 10; 
            next *= 10;
        }
        return steps;
    }
};
