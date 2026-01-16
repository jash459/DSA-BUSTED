class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        const int MOD = 1e9 + 7;

        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        vector<int> hGap, vGap;
        for (int i = 1; i < hFences.size(); i++)
            hGap.push_back(hFences[i] - hFences[i - 1]);
        for (int i = 1; i < vFences.size(); i++)
            vGap.push_back(vFences[i] - vFences[i - 1]);


        vector<int> hPref(hGap.size() + 1, 0);
        vector<int> vPref(vGap.size() + 1, 0);

        for (int i = 0; i < hGap.size(); i++)
            hPref[i + 1] = hPref[i] + hGap[i];
        for (int i = 0; i < vGap.size(); i++)
            vPref[i + 1] = vPref[i] + vGap[i];

        unordered_set<int> hDiff;
        for (int i = 0; i < hPref.size(); i++) {
            for (int j = i + 1; j < hPref.size(); j++) {
                hDiff.insert(hPref[j] - hPref[i]);
            }
        }

        int best = -1;
        for (int i = 0; i < vPref.size(); i++) {
            for (int j = i + 1; j < vPref.size(); j++) {
                int diff = vPref[j] - vPref[i];
                if (hDiff.count(diff)) {
                    best = max(best, diff);
                }
            }
        }

        if (best == -1) return -1;
        return (1LL * best * best) % MOD;
    }
};
