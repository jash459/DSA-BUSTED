class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        //swapping left and right subtree
        TreeNode* temp = root -> left;
        root -> left = root -> right;
        root -> right = temp;
        //recursively call to left and right subtree
        invertTree(root -> left);
        invertTree(root -> right);
        return root;
    }
};