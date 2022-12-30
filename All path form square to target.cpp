class Solution {
public:
void dfs(vector<vector<int>>& graph, vector<vector<int>>& result, vector<int> path, int src, int dst) {
    path.push_back(src);
    if(src == dst) {
        result.push_back(path);
        return;
    }

    for(auto node : graph[src])
        dfs(graph, result, path, node, dst);
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> paths; vector<int> path;
    int node = graph.size();
    if(node == 0) return paths;
    dfs(graph, paths, path, 0, node - 1);
    return paths;
    }
};