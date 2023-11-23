class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
            vector<bool>res; // to store results
            int m = l.size();
            for(int i=0;i<m;i++){
              int low = l[i];
              int high = r[i];
              vector<int>temp(nums.begin() + low , nums.begin() + high+1);
              sort(temp.begin()  , temp.end()); // find common diff
              int diff = temp[1] - temp[0];
              bool f = true;
              for(int i=2;i<temp.size();i++){
                if (diff!=temp[i]-(temp[i-1])) f=false; // if common diff not same i.e no arithmetic seq
              }
              res.push_back(f);
            }
            return res;
    }
};
