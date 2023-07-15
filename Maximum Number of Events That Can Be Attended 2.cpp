class Solution {
public:
    vector<vector<int>> dp;
    int n;

    int attend(int i, int num, vector<vector<int>>& events){
        // Base case: If we have attended num events or reached the end of events list, return 0.
        if (i == n || num == 0) return 0;

        // If the result for this state is already calculated, return it from the dp table.
        if (dp[i][num] != -1) return dp[i][num];

        // Attend the event i and move on to the next available event that starts after this one ends.
        int j = upper_bound(events.begin() + i, events.end(), vector<int>{events[i][1] + 1, 0, 0}) - events.begin();
        int attend_i = events[i][2] + attend(j, num - 1, events);

        // Skip the event i and move on to the next event.
        int skip_i = attend(i + 1, num, events);

        // Choose the maximum between attending the current event (attend_i) and skipping it (skip_i).
        int ans = max(attend_i, skip_i);

        // Store the result in the dp table and return it.
        return dp[i][num] = ans;
    }

    int maxValue(vector<vector<int>>& events, int num) {
        // Get the total number of events in the input.
        n = events.size();

        // Sort the events list based on their start times.
        sort(events.begin(), events.end());

        // Initialize the dp table with -1 (indicating that the result for this state is not yet calculated).
        dp.assign(n + 1, vector<int>(num + 1, -1));

        // Start the recursive process and return the maximum value possible.
        return attend(0, num, events);
    }
};