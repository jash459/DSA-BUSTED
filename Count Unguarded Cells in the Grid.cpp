class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& cell, char direction){
        if(i<0 or i>=cell.size() or j<0 or j>=cell[i].size() or cell[i][j]==2 or cell[i][j]==3)
            return;
        cell[i][j]=1;
        if(direction=='U')
            dfs(i-1,j,cell,'U');
        if(direction=='D')
            dfs(i+1,j,cell,'D');
        if(direction=='L')
            dfs(i,j-1,cell,'L');
        if(direction=='R')
            dfs(i,j+1,cell,'R');
    }
    
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> cell(m, vector<int>(n));
        for(int i=0;i<guards.size();i++){
            cell[guards[i][0]][guards[i][1]]=2;
        }
        for(int i=0;i<walls.size();i++){
            cell[walls[i][0]][walls[i][1]]=3;
        }
        for(int i=0;i<guards.size();i++){
            dfs(guards[i][0]-1,guards[i][1],cell,'U'); 
            dfs(guards[i][0]+1,guards[i][1],cell,'D'); 
            dfs(guards[i][0],guards[i][1]-1,cell,'L'); 
            dfs(guards[i][0],guards[i][1]+1,cell,'R'); 
        }
        int count=0;
        for(auto x:cell){
            for(auto y:x)
                if(y==0) count++;
        }
        return count;
    }
};
