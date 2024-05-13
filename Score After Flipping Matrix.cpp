class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int ans=0,n=grid.size(),m=grid[0].size();
        for(int i=0;i<n;i++){ 
            if(grid[i][0]!=1){ 
                for(int j=0;j<m;j++){
                    if(grid[i][j]==0){
                        grid[i][j]=1;
                    }
                    else{
                        grid[i][j]=0;
                    }
                }
            }
        }
        for(int i=0;i<m;i++){ 
            int x=0;
            for(int j=0;j<n;j++){
                if(grid[j][i]==1){
                    x++;
                }
            }
            if(x<ceil(n/2.0)){
                for(int j=0;j<n;j++){
                    if(grid[j][i]==1){
                        grid[j][i]=0;
                    }
                    else{
                        grid[j][i]=1;
                    }
                }
            }
        }
        for(auto x:grid){ 
            int z=0,f=m-1;
            for(auto y:x){
                z+=pow(2,f)*y;
                f--;
            }
            ans+=z;
        }
        return ans;
    }
};
