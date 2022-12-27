class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& v, int k,int ans=0) {
        int n=v.size();
        vector<int> idn(n);
        for(int i=0;i<n;i++)idn[i]=i;
        sort(idn.begin(),idn.end(),[&](int i,int j){
            return cap[i]-v[i]<cap[j]-v[j];
        });
        for(int i:idn){
            if(k>=cap[i]-v[i])ans+=1,k-=(cap[i]-v[i]);
            else break;
        }
        return ans;
    }
};