class Solution {
public:
    bool helper(vector<int>& position, int n, int m, int mid)
    {
        int cntCows=1; // count of cows we can place in current combinations
        int last=position[0];  // position of 1st cow
       
       for(int i=1;i<n;i++){
           if(position[i]-last>=mid){
            cntCows++; // increment the count if the dist. bw 2 consecutive is >= given distance
            if(cntCows==m) return true;  // we are able to place each cows with the given distance
            last=position[i];  // place the next cow at ith position
        }
       } 
       return false;  // return false if all cows are not able to place.
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());  // sort array 
        int low=1,ans=-1;  
        int high=position[position.size()-1]-position[0];  // max dis. at which next cow can place
       
        while(low<=high)  // iterate from low to high
        {
            int mid=low+(high-low)/2;
            if((helper(position, n, m, mid)))  // check if all cows can place with given distance, then move low at mid+1, as we can want to find the max. among min. dist.
            {
                ans=mid; 
                low=mid+1;
            }
            else high=mid-1;  // if cows can't place, then elminate the search space
        }
        return ans; // return final ans.
    }
};
