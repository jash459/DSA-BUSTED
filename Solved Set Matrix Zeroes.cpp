class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int n = matrix.size(), m = matrix[0].size();

        // Check if row0 has any 0
        bool row0 = any_of(matrix[0].begin(), matrix[0].end(),
                           [](int x) { return x == 0; });
        
        // Check if col0 has any 0
        bool col0 = 0;
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) {
                col0 = 1;
                break;
            }
        }

        // Use first row and column as markers
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set rows and columns to zero based on markers
        for (int i = 1; i < n; i++) {
            if (matrix[i][0] == 0) {
                fill(matrix[i].begin(), matrix[i].end(), 0);
            }
        }

        for (int j = 1; j < m; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 0; i < n; i++) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Apply row0 and col0 if needed
        if (row0) {
            fill(matrix[0].begin(), matrix[0].end(), 0);
        }

        if (col0) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
