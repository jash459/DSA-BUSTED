class Solution {
public:
    
    int vis[105][105]; // Declare a 2D array to mark visited cells.
    vector<pair<int,int>>dir={{1,0},{-1,0},{0,-1},{0,1}}; // Define 4 possible directions to move: down, up, left, right.

    // Depth-first search function to explore cells with a maximum difference of 'mid'.
    void ok(int x, int y, int mid, vector<vector<int>>& heights) {
        if (!vis[x][y]) { // If the cell has not been visited.
            vis[x][y] = 1; // Mark the cell as visited.
            int n = heights.size(); // Get the number of rows in the 'heights' matrix.
            int m = heights[0].size(); // Get the number of columns in the 'heights' matrix.
            
            // Loop through the four possible directions.
            for (int i = 0; i < 4; i++) {
                int X = x + dir[i].first; // Calculate the new row coordinate.
                int Y = y + dir[i].second; // Calculate the new column coordinate.
                
                // Check if the new coordinates are out of bounds.
                if (X < 0 || X >= n || Y < 0 || Y >= m)
                    continue; // Skip this direction if out of bounds.
                
                // Check if the absolute difference between the heights is less than or equal to 'mid'.
                if (abs(heights[x][y] - heights[X][Y]) <= mid)
                    ok(X, Y, mid, heights); // Recursively explore this direction.
            }
        }
    }
    
    // Function to find the minimum effort path using binary search.
    int minimumEffortPath(vector<vector<int>>& heights) {
        int l = 0; // Initialize the left bound of the binary search.
        int r = 1e9 + 2; // Initialize the right bound of the binary search.
        int n = heights.size(); // Get the number of rows in the 'heights' matrix.
        int m = heights[0].size(); // Get the number of columns in the 'heights' matrix.
        
        while (l < r) { // Perform binary search until the left bound is less than the right bound.
            int mid = (l + r) / 2; // Calculate the middle value.
            memset(vis, 0, sizeof(vis)); // Initialize the visited array to 0.
            ok(0, 0, mid, heights); // Start the depth-first search with 'mid' as the maximum difference.
            
            if (vis[n - 1][m - 1] == 1)
                r = mid; // If the destination cell is reachable, update the right bound.
            else
                l = mid + 1; // If the destination cell is not reachable, update the left bound.
        }
        
        return l; // Return the minimum effort required to reach the destination.
    }
};