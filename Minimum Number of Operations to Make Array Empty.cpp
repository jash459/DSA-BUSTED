
class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto a: nums){
            mpp[a]++;
        }

        int count=0;
        for(auto a: mpp){
            int t = a.second;
            if(t==1)return -1;
            count += t/3;
            if(t%3)count++;
        }
        return count;
    }
};

