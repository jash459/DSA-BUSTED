class Solution {
public:
    string w1, w2;
    int n1, n2;
    vector<vector<int>> dp;
    
    int LCS(int x, int y){//Find the ASCII sum in LCS
        if (x == n1 || y == n2) return 0;
        if (dp[x][y] != INT_MAX) return dp[x][y];     
        int sum;
        if (w1[x] == w2[y]) 
            sum = w1[x]+LCS(x+1, y+1);
        else 
            sum = max(LCS(x+1, y), LCS(x, y+1));
        
        return dp[x][y] = sum;
    }

    int minimumDeleteSum(string s1, string s2) {
        n1 = s1.size();
        n2 = s2.size();
        w1 = s1;
        w2 = s2;
        dp.assign(n1, vector<int>(n2, INT_MAX));
        int AsciiSum=0;
        for(char c: w1) AsciiSum+=c;
        for(char c: w2) AsciiSum+=c;
        return AsciiSum-2*LCS(0, 0);
    }
};