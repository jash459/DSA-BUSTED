class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        unordered_map<int,int>mpp;
        unordered_set<int>st;
        for(auto i:arr)mpp[i]++;
        for(auto i:mpp)st.insert(i.second);
        return mpp.size()==st.size();
    }
};
