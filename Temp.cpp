class Solution {
  public:
    int maxOnes(vector<int>& arr) {
        // code here
        int n = arr.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            ans+=arr[i];
            if(arr[i]==0) arr[i]=1;
            else arr[i]  = -1;
         }
        int temp =0;
        int curr =0;
        for(int i=0;i<n;i++){
            curr+= arr[i];
            if(curr<0) curr =0;
             temp = max(curr,temp);
        }
        return ans+temp;
        
    }
};
