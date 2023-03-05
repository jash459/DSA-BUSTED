class Solution {
public:
  int minJumps(vector<int>& arr) {
    const int n = arr.size();
    // {a: indices}
    unordered_map<int, vector<int>> graph;
    // Initialize queue with first index and mark as seen
    queue<int> q{{0}};
    vector<bool> seen(n);
    seen[0] = true;

    // Create graph where keys are elements and values are their indices in arr
    for (int i = 0; i < n; ++i)
      graph[arr[i]].push_back(i);

    // BFS
    for (int steps = 0; !q.empty(); ++steps) {
      // Process all nodes at current level
      for (int sz = q.size(); sz > 0; --sz) {
        const int i = q.front();
        q.pop();
        // If last index is reached, return number of steps
        if (i == n - 1)
          return steps;
        seen[i] = true;
        const int u = arr[i];
        // Add adjacent indices to graph
        if (i + 1 < n)
          graph[u].push_back(i + 1);
        if (i - 1 >= 0)
          graph[u].push_back(i - 1);
        // Process all adjacent nodes
        for (const int v : graph[u]) {
          if (seen[v])
            continue;
          q.push(v);
        }
        // Clear indices in graph to avoid revisiting
        graph[u].clear();
      }
    }
    // Should never reach here
    throw;
  }
};