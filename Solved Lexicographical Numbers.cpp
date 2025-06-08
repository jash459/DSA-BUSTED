class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for (int i = 1; i < 10; i++) {
            dfs(i, n, result);
        }
        return result;
    }

private:
    void dfs(int current, int max, vector<int>& result) {
        if (current > max) return;
        result.push_back(current);
        for (int i = 0; i < 10; i++) {
            int next = current * 10 + i;
            if (next > max) return;
            dfs(next, max, result);
        }
    }
};
