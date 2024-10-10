class Solution {
public:
    int maxWidthRamp(vector<int>& a) {
        vector<int> s;
        int m = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (s.empty() || a[s.back()] > a[i]) {
                s.push_back(i);
            }
        }
        for (int j = a.size() - 1; j >= 0; --j) {
            while (!s.empty() && a[s.back()] <= a[j]) {
                m = max(m, j - s.back());
                s.pop_back();
            }
        }
        return m;
    }
};
