class Solution {
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) 
    {
        UnionFind graph(n);
        vector<unsigned> cost(n, UINT_MAX);
        for (auto& vec: edges){
            int u=vec[0], v=vec[1], w=vec[2];
            int wt=cost[graph.Find(u)] & cost[graph.Find(v)] & w;
            graph.Union(u, v);
            int rt=graph.Find(u);
            cost[rt]&=wt;
        }
        int m=query.size();
        vector<int> ans(m, -1);
        for(int i=0; i<m; i++){
            int s=query[i][0], t=query[i][1];
            if (graph.connected(s, t))
                ans[i]=cost[graph.Find(s)];
        }
        return ans;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
