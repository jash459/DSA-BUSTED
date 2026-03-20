class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int rows = m - k + 1, cols = n - k + 1;

        vector<vector<int>> ans(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                vector<int> vals;

                for (int x = i; x < i + k; x++) {
                    for (int y = j; y < j + k; y++) {
                        vals.push_back(grid[x][y]);
                    }
                }

                sort(vals.begin(), vals.end());

                int best = INT_MAX;
                for (int t = 1; t < vals.size(); t++) {
                    if(vals[t] != vals[t-1])best = min(best, vals[t] - vals[t - 1]);
                }

                ans[i][j] = (best == INT_MAX) ? 0 : best;
            }
        }

        return ans;
    }
};
