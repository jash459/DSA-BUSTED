bool dfs(vector<vector<int>> &graph, int src, vector<bool> &visited, vector<bool> &dfsVisited, set<int> &cycle){
    visited[src]=true;
    dfsVisited[src]=true;
    
    for(int i=0;i<graph[src].size();i++){
        int child=graph[src][i];
        if(visited[child]==false){
            if(dfs(graph,child,visited,dfsVisited,cycle)){
                cycle.insert(child);
                return true;
            }
        }else{
            if(dfsVisited[child]==true){
                cycle.insert(child);
                return true;
            }
        }
    }
    dfsVisited[src]=false;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n=graph.size();
    
    vector<bool> visited(n,false), dfsVisited(n,false);
    set<int> cycle; // storing all elements who are part of any cycle detected
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            if(dfs(graph,i,visited,dfsVisited,cycle)) cycle.insert(i);
        }
    }
    
	vector<int> ans;
    for(int i=0;i<n;i++){
        if(cycle.find(i)==cycle.end()) ans.push_back(i);
    }
    return ans;
}