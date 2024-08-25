class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> left = postorderTraversal(root->left);
        vector<int> right = postorderTraversal(root->right);
        left.insert(left.end(), right.begin(), right.end());
        left.push_back(root->val);
        return left;
    }
};
