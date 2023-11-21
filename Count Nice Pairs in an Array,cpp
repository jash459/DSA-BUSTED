class Solution {
public:
int mod = 1e9+7;
int reverse_(int x){
  string str = to_string(x);
  reverse(str.begin() , str.end());
  return stoi(str);
}
    int countNicePairs(vector<int>& nums) {
            unordered_map<int,int>mp;
            int cnt = 0;
            for(auto num: nums){
              int num_revsered = reverse_(num);
               cnt = (cnt %mod+ mp[num - num_revsered]%mod)%mod;
              mp[num-num_revsered]++;
            }
            return cnt;
    }
};
