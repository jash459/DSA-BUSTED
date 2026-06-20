class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& r) {
        if(r.empty()) return n - 1;

        sort(r.begin(), r.end());

        int id = 1, h = 0;

        for(auto &x : r) {
            x[1] = min(x[1], x[0] - id + h);
            id = x[0];
            h = x[1];
        }

        for(int i = r.size() - 2; i >= 0; i--) {
            r[i][1] = min(r[i][1], r[i+1][1] + r[i+1][0] - r[i][0]);
        }

        int ans = n - r.back()[0] + r.back()[1];
        id = 1; h = 0;

        for(auto &x : r) {
            int steps = x[0] - id - abs(x[1] - h);
            int higher = max(x[1], h);
            ans = max(ans, higher + steps / 2);
            id = x[0];
            h = x[1];
        }

        return ans;
    }
};
