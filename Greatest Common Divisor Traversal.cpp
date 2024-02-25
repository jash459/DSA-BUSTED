constexpr int maxn = 100000;
vector<int> pd[maxn + 1];

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        // Calculate prime divisors for numbers from 2 to maxn if not already calculated
        if (pd[2].empty()) {
            for (int i = 2; i <= maxn; i += 1) {
                if (pd[i].empty()) {
                    // Calculate prime divisors for multiples of i
                    for (int j = i; j <= maxn; j += i) {
                        pd[j].push_back(i);
                    }
                }
            }
        }
        
        // Map to store the indices of elements with the same prime divisors
        map<int, vector<int>> indexMap;
        int n = nums.size();
        vector<vector<int>> graph(n);
        
        // Build the index map and adjacency list
        for (int i = 0; i < n; i += 1) {
            for (int primeDivisor : pd[nums[i]]) {
                indexMap[primeDivisor].push_back(i);
            }
        }
        
        // Construct the graph using the index map
        for (auto& [primeDivisor, indices] : indexMap) {
            for (int i = 1; i < indices.size(); i += 1) {
                graph[indices[0]].push_back(indices[i]);
                graph[indices[i]].push_back(indices[0]);
            }
        }
        
        vector<int> visited(n);
        int m = 0; // Number of visited nodes
        
        // Depth-first search to count the number of visited nodes
        function<void(int)> dfs = [&](int u) {
            if (visited[u]) {
                return;
            }
            m += visited[u] = 1;
            for (int v : graph[u]) {
                dfs(v);
            }
        };
        
        dfs(0); // Start DFS from node 0
        
        return n == m; // Check if all nodes are visited
    }
};
