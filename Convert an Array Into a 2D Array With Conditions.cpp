class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int, int> mpp;
        for(auto i: nums){
            mpp[i]++;
        }  

        while(!mpp.emppty()){
            vector<int> tempp;
            for(auto it = mpp.begin(); it != mpp.end(); ){
                tempp.push_back(it->first);
                it->second--;
                if(it->second == 0){
                    it = mpp.erase(it);
                } else {
                    ++it;
                }
            }
            ans.push_back(tempp);
        }
        return ans;
    }
};
