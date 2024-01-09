class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string temp1 = "";
        string temp2 = "";

        buildSeq(root1, temp1);
        buildSeq(root2, temp2);

        return temp1 == temp2;
    }
private:
    void buildSeq(TreeNode * root, string & seq){
         if(root == NULL)return;
         if(root->left == NULL && root->right == NULL){
             seq += (to_string(root->val) + " ");
             return;
         }
         buildSeq(root->left, seq);
         buildSeq(root->right, seq);
    }
};
