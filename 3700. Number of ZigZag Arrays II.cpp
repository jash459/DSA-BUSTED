class Solution {
public:
    const int MOD=1e9+7;
    using ll=long long;
    
    vector<vector<ll>> matmul(vector<vector<ll>>&a,vector<vector<ll>>b){
        int n=a.size();
        int m=a[0].size();
        int p=b[0].size();
        vector<vector<ll>>c(n,vector<ll>(p,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<p;j++){
                for(int k=0;k<m;k++){
                    c[i][j]=(c[i][j]+a[i][k]*b[k][j])%MOD;
                }
            }
        }
        return c;
    }
    vector<vector<ll>> p(vector<vector<ll>>&a,int b){
        int n=a.size();
        vector<vector<ll>>ans(n,vector<ll>(n,0));
        for(int i=0;i<n;i++)ans[i][i]=1;
        while(b){
            if(b&1)ans=matmul(ans,a);
            a=matmul(a,a);
            b/=2;
        }return ans;
    }

    int zigZagArrays(int n, int l, int r) {
        int m=r-l+1;
        vector<vector<ll>>a(2*m,vector<ll>(2*m,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<i;j++)a[i][j+m]=1;
            for(int j=i+1;j<m;j++)a[i+m][j]=1;
        }
        a=p(a,n-1);
        long long ans=0;
        for(int i=0;i<2*m;i++){
            for(int j=0;j<2*m;j++){
                ans=(ans+a[i][j])%MOD;
            }
        }return (int)(ans);
    }
};
