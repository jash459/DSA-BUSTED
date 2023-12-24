class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int operationsCount = 0;

        for (int i = 0; i < n; i++) {
            // Check if the current character is different from the expected one based on the index
            if (s[i] - '0' != i % 2) {
                operationsCount++;
            }
        }

        // Return the minimum of operationsCount and (n - operationsCount)
        return min(operationsCount, n - operationsCount);
    }
};
