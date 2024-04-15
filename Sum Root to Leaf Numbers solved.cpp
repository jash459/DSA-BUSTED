/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 #define ll long long
class Solution {
public:

    void dfs(TreeNode *root, ll &result , ll tmp){
        if(root->left== NULL && root->right==NULL){
            tmp = tmp*10 + root->val;
            result+=tmp;
            return;
        }
        tmp = tmp*10 + root->val;
        if(root->left) dfs(root->left,result,tmp);
        if(root->right) dfs(root->right,result,tmp);
    }

    int sumNumbers(TreeNode* root) {
        ll result =0;
        dfs(root,result,0);
        return int(result);
    }
};
