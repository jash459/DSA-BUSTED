class Solution {
public:
    bool bfs(vector<vector<int>> adj,int src,int target){
        int n=adj.size();
        queue<int> q;
        q.push(src);
        vector<int> vis(n,0);
        vis[src]=1;
        while(!q.empty()){
            int nd=q.front(); q.pop();
            if(nd==target) return true;
            for(auto it:adj[nd]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        return false;
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(n);
        for(auto it:prerequisites){
            adj[it[0]].push_back(it[1]);
        }
        vector<bool> ans(queries.size(),false);
        for(int i=0;i<queries.size();i++){
            auto it=queries[i];
            int nd=it[0],target=it[1];
            if(bfs(adj,nd,target)) ans[i]=true;
        }
        return ans;
    }
};
