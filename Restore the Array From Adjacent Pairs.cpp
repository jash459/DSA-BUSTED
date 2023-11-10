#pragma GCC optimize("O3")
class Solution {
public:
    unordered_map<int, vector<int>> adj;
    void build_adj(vector<vector<int>>& adjacentPairs){
        #pragma unroll
        for(auto& e: adjacentPairs){
            int v0=e[0], v1=e[1];
            if (adj.count(v0)) adj[v0].push_back(v1);
            else adj[v0]={v1};
            if (adj.count(v1)) adj[v1].push_back(v0);
            else adj[v1]={v0};
        }
    }
    vector<int> ans;
    void dfs(int i, int prev){
        ans.push_back(i);
        for(int j: adj[i]){
            if (j==prev) continue;
            dfs(j, i);
        }

    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        build_adj(adjacentPairs);
        int root=INT_MAX;
        #pragma unroll
        for(auto [i, vec]: adj){
            if (vec.size()==1){
                root=i;
                break;
            }
        }
        dfs(root, INT_MAX);
        return ans;
    }
};
