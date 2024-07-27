class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> A(26, vector<int>(26, 1e8));
        for(int i = 0; i < 26; i++) A[i][i] = 0;
        for(int i = 0; i < original.size(); i++) {
            A[original[i] - 'a'][changed[i] - 'a'] = min(A[original[i] - 'a'][changed[i] - 'a'], cost[i]);
        }
        for(int k = 0; k < 26; k++) {
            for(int i = 0; i < 26; i++) {
                for(int j = 0; j < 26; j++) {
                    A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
                }
            }
        }
        long long ans = 0;
        for(int i = 0; i < source.size(); i++) {
            if(A[source[i] - 'a'][target[i] - 'a'] >= 1e8) return -1;
            ans += A[source[i] - 'a'][target[i] - 'a'];
        }
        return ans;
    }
};
