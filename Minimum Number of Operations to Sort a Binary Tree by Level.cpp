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
private:
    int minSwaps(vector<int>& arr) {
        map<int, int> mp;
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        
        for(int i=0; i<arr.size(); i++){
            mp[temp[i]] = i;
        }
        int ans=0;
        for(int i=0; i<arr.size();){
            int ind = mp[arr[i]];
            if(ind == i){
                i++;
            }
            else{
                int temp = arr[i];
                arr[i] = arr[ind];
                arr[ind] = temp;
                ans++;
            }
        }
        return ans;
    }
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        int ans=0;
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            while(size--){
                auto it = q.front();
                q.pop();
                temp.push_back(it->val);
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
            ans+=minSwaps(temp);
        }
        return ans;
    }
};
