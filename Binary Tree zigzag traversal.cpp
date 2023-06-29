class Solution {
public:
   vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>answer;
        if(!root)return answer;
        queue<TreeNode*>q;
        q.push(root);
        int i=0;
        while(!q.empty()){
           int sz=q.size();
           vector<int>v(sz);
           int j=0,n=sz;
           while(sz--){
               TreeNode * f=q.front();
               q.pop();
               if(i%2==0)
               v[j]=f->val;
               else v[n-j-1]=f->val;
               j++;
               if(f->left)q.push(f->left);
               if(f->right)q.push(f->right);
           }
           i++;
           answer.push_back(v);

        }
        return answer;
    
    }
};