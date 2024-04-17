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
class Solution {
public:
    string ans = "";
    void preorder(TreeNode *root, string op){
        if(!root) return;

        if(!root->left && !root->right){
            if(ans == "") ans = (char)(root->val + 'a') + op;
            else{
                ans = min(ans,(char)(root->val + 'a') + op);
            }
        }

        preorder(root->left,(char)(root->val + 'a') + op);
        preorder(root->right,(char)(root->val + 'a') + op);
    }

    string smallestFromLeaf(TreeNode* root) {
        string output = "";
        preorder(root,output);
        return ans;
    }
};
