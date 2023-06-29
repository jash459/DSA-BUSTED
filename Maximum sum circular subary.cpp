class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int totalsum=0,currsum1=0,currsum2=0,mxsumsubary=INT_MIN,minsum_subary=INT_MAX;   
        for(auto i:A)
        {
            totalsum+=i; currsum1+=i; currsum2+=i;
            mxsumsubary=max(mxsumsubary,currsum1);
            if(currsum1<0) currsum1=0;
           minsum_subary=min(currsum2,minsum_subary);
            if(currsum2>0) currsum2=0;
        }
        return (totalsum==minsum_subary)?mxsumsubary:max(mxsumsubary,totalsum-minsum_subary);  
    }
};