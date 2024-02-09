class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
       vector<int> dp(n,1), hash(n);
       int maxi=1;
       int lastind=0;
       sort(nums.begin(), nums.end());
       
       for(int ind=0 ; ind<n;ind++){
           hash[ind]=ind;
           for(int prev_ind=0;prev_ind< ind;prev_ind++){
               if(nums[ind]%nums[prev_ind]==0 && 1+dp[prev_ind]>dp[ind]){
                   dp[ind]=1+dp[prev_ind];
                   hash[ind]=prev_ind;
               }
           }
          if(dp[ind]>maxi){
              maxi=dp[ind];
              lastind=ind; 
          }
       }   
       // now we need to do everything in reverse order.
       // so instead of these lets take vector..
       
       vector<int> temp;
       temp.push_back(nums[lastind]);
       while(hash[lastind] != lastind){
           lastind=hash[lastind];
           temp.push_back(nums[lastind]);
       }
       reverse(temp.begin(),temp.end());
    //    for(auto it:temp) cout<< it << " ";
    //    cout<<endl;
    //    return maxi;

    return temp;
    }
};
