class Solution {
public:
    static int longestSubarray(vector<int>& nums) {
        const int n=nums.size();
        int maxLen=0, xMax=0, len=0;
        for(int i=0; i<n; i++){
            while(i<n && nums[i]==xMax){
                i++;
                len++;
            }
            if (i==n) {
                maxLen=max(maxLen, len);
                break;
            }
            int x=nums[i];
            if (x>xMax){
                xMax=x;
                maxLen=len=1;
            }
            else if (x<xMax) {
                maxLen = max(maxLen, len);
                len=0;
            }
        //    cout<<i<<"->"<<xMax<<", len="<<len<<", maxLen="<<maxLen<<endl;
        }
        return maxLen;
    }
};
