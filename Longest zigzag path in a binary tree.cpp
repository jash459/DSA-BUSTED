#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int MAX;
    unordered_map<TreeNode*, vector<int>> dp;
public:
    int longestZigZag(TreeNode* root) {
        dp.clear();
        dfs(root);
        return MAX;
    }

    void dfs(TreeNode* root) {
        if (!root) return;

        if (!root->left && !root->right) {
            dp[root] = {0, 0};
            return;
        }

        dfs(root->left);
        dfs(root->right);

        int left = 0, right = 0;

        if (dp.find(root->left) != dp.end())
            left = 1 + dp[root->left][1];

        if (dp.find(root->right) != dp.end())
            right = 1 + dp[root->right][0];

        dp[root] = {left, right};
        MAX = max(MAX, max(left, right));
    }
};