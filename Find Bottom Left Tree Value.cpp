class Solution {
public:
    // using info=pair<TreeNode*, int>;
    int findBottomLeftValue(TreeNode* root) {
        int ans=0, level=-1;
        queue<TreeNode*> q;//no need info for level, BFS is good 
        q.emplace(root);
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            if (!node) continue;
            // if (h>=level){//always true drop it, & make it simpler
            ans=node->val;
            q.emplace(node->right);//FIFO
            q.emplace(node->left);
        }
        return ans;
    }
};
