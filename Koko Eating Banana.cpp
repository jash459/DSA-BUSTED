class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = piles[0];
        for (int i = 0; i < piles.size(); i++) {
            r = max(r, piles[i]);
        }
        
        int ans = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (check(piles, h, m)) {
                r = m - 1;
                ans = m;
            } else {
                l = m + 1;
            }
        }
        
        return ans;
    }

    bool check(vector<int>& piles, int h, int k) {
        if (k == 0) {
            return false;
        }
        
        int i = 0;
        while (h >= 0 && i < piles.size()) {
            h -= ceil((double)piles[i] / k);
            i++;
        }
        
        return h >= 0 && i == piles.size();
    }
};