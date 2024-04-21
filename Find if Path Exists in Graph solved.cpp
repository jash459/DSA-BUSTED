class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        unordered_map<int, vector<int>> hash;
        for(auto& edge : edges){
            hash[edge[0]].push_back(edge[1]);
            hash[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        q.push(start);
        vector<bool> visitpath(n, false);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(curr == end) return true;
            for(auto& node : hash[curr]){
                if(!visitpath[node]){
                    q.push(node);
                    visitpath[node] = true;
                }
            }
        }
        return false;
    }
};
