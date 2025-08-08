class Solution {
public:
    double val(int a,int b, vector<vector<double>> &dp){
        if(a<=0&&b>0)return 1;
        if(a==0&&b==0)return 0.5;
        if(a>0&&b<=0)return 0;
        if(a<=0&&b<=0)return 0.5;
        if(dp[a][b]!=-1)return dp[a][b];

        double w=0.25*val(a-100,b,dp);
        double x=0.25*val(a-75,b-25,dp);
        double y=0.25*val(a-50,b-50,dp);
        double z=0.25*val(a-25,b-75,dp);

        return dp[a][b]=w+x+y+z;
    }
    double soupServings(int n) {
        if (n > 4800)
            return 1;
        vector<vector<double>> dp(n+1,vector<double>(n+1,-1));
        return val(n,n,dp);
    }
};
