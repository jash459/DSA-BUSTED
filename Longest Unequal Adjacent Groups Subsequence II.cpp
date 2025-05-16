class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
    for (int j = 0; j < i; j++) {
    if (groups[i] != groups[j] && 
        differByOneChar(words[i], words[j]) && dp[i] < dp[j] + 1) {
        dp[i] = dp[j] + 1;
        parent[i] = j;
                }
            }
    }
};
