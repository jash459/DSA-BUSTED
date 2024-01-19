class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
          int sum =0;
        for (int i =  matrix.size()-2; i>=0; --i){
            for (int j = 0; j < matrix[0].size(); ++j){
                if (j>0 && j <matrix[0].size()-1)
                    matrix[i][j] += min(matrix[i+1][j], min(matrix[i+1][j-1], matrix[i+1][j+1]));
                else if (j == 0)
                    matrix[i][j] += min(matrix[i+1][j], matrix[i+1][j+1]);
                else 
                    matrix[i][j] += min(matrix[i+1][j],matrix[i+1][j-1]);
            }
        }
        sum = matrix[0][0];
        for (int i=0; i <matrix[0].size(); ++i)
        if (sum > matrix[0][i])
            sum = matrix[0][i];
        return sum;
    }
};
