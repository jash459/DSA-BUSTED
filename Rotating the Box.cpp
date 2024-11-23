class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n=box.size();
        int m=box[0].size();

        vector<vector<char>> new_box(m,vector<char>(n,'.'));
        for (int row = 0; row < n; row++) {
            for (int col = m - 1; col >= 0; col--) {
                if (box[row][col] == '*') {
                    new_box[col][n - 1 - row] = '*';
                } else if (box[row][col] == '#') {
                    int empty_col = col;
                    while (empty_col + 1 < m && box[row][empty_col + 1] == '.') {
                        empty_col++;
                    }
                    swap(box[row][col], box[row][empty_col]);
                }
            }
        }

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                new_box[col][n - 1 - row] = box[row][col];
            }
        }

        return new_box;
    }  
    
};
