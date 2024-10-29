class Solution {
public:
    int bfs(vector<vector<int>>&g,vector<vector<int>>&vis,int i,int j){
        int n=g.size();
        int m=g[0].size();
        int ans=0;
        vis[i][j]=1;
        queue<pair<pair<int,int>,int>>q;
        q.push({{i,j},0});
        int row[]={-1,0,+1};
        int col[]={+1,+1,+1};
        //int ans=0;
        while(!q.empty()){
            int a=q.front().first.first;
            int b=q.front().first.second;
            int rs=q.front().second;
            q.pop();
            ans=max(ans,rs);
            for(int i=0;i<3;i++){
                int r=a+row[i];
                int c=b+col[i];
                if(r>=0&&c>=0&&r<n&&c<m&&vis[r][c]==0&&g[r][c]>g[a][b]){
                    vis[r][c]=1;
                    q.push({{r,c},rs+1});
                }
            }
        }
        return ans;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,bfs(grid,vis,i,0));
        }
        return ans;
    }
    
};
