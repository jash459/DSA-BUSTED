class Solution {
private:
    int memo[101][101];
	
    int recursion(const string &s, int i, int K){
        int n = s.length(), k = K;
        if(n-i<=k) return 0;
        if(memo[i][k]!=-1) return memo[i][k];
		
        int ans = k?recursion(s,i+1,k-1):101, c = 1;
        for(int j=i+1;j<=n;j++){
			
            ans = min(ans,1+((c>99)?3:(c>9)?2:(c>1)?1:0)+recursion(s,j,k));
			
            if(j<n and s[i]==s[j]) c++;
			
            else if(--k<0) break;
        }
        return memo[i][K] = ans;
    }
    
public:
    int getLengthOfOptimalCompression(string s, int k) {
        memset(memo,-1,sizeof(memo));
        return recursion(s,0,k);
    }
};
