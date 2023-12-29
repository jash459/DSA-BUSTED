/*

idea : Select d subarrays and take the sum of max across all those subarrays and find the minimum sum obtained.

*/

int dp[301][11];
class Solution {
    int n;
    int solve(int i,int j,vector<int>& jd, int d){
        if(j>d){
            return 1e9;
        }
        if(i==n){
            if(j==d){
                return 0;
            }
            else{
                return 1e9;
            }
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=1e9;
        int mx=jd[i];
        for(int k=i;k<n;k++){
            mx=max(mx,jd[k]);    // simultaneously determining the maximum of the subarray.
            ans=min(ans,mx+solve(k+1,j+1,jd,d));   //deciding where to start a new partition from , here : new partition starts from k+1.This means the subarray we choose starts from i and ends at k ,i,e jd[i..k] and thats why we incremented j i.e j+1 by this we increased the count of subarrays choosen.  
        }
        return dp[i][j]=ans;
    }
public:
    int minDifficulty(vector<int>& jd, int d) {
        
        n=jd.size();
        if(d>n){
            return -1;
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=d;j++){
                dp[i][j]=-1;
            }
        }
        int res=solve(0,0,jd,d);
        return res;
        
    }
};
