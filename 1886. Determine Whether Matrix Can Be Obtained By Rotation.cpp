class Solution {
public:
    static bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        const int n=mat.size();
        uint8_t rot90=15;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++){
                uint8_t cur=0;
                cur|=(mat[i][j]==target[i][j]);
                cur|=((mat[j][n-1-i]==target[i][j])<<1);
                cur|=((mat[n-1-i][n-1-j]==target[i][j])<<2);
                cur|=((mat[n-1-j][i]==target[i][j])<<3);
                rot90&=cur;
            }
        return rot90!=0;
    }
};
