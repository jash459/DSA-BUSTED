class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& cur, vector<int>& nums){
        if (cur.size()==nums.size()){
            ans.push_back(cur);
            return ;
        } 
        for (int x:nums){
            if (find(cur.begin(), cur.end(), x)==cur.end()){
                cur.push_back(x);
                backtrack(cur, nums);
                cur.pop_back();
            }
        }
    }    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur={};
        backtrack(cur, nums);
        return ans;
    }
};