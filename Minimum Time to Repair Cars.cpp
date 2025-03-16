#define ll long long
class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        ll l = 1, r = 1e14, res = 0;
        while (l <= r) {
            ll mid = (l + r) / 2, k = 0;
            for (int rank : ranks) {
                k += sqrt(mid / rank);
                if (k >= cars) break;  
            }
            if (k >= cars) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};
