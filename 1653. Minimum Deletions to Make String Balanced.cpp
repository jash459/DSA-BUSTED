// Optimizations for faster execution (Beats 100%)
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

static const bool _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return false;
}();

class Solution {
public:
    int minimumDeletions(string s) {
        int res = 0;
        int b_count = 0;
        for (const char& c : s) {
            if (c == 'b') {
                b_count++;
            } else {
                if (b_count > 0) {
                    res++;      
                    b_count--;  
                }
            }
        }
        
        return res;
    }
};
