class Solution {
public:
    static bool comp(pair<long long,long long>&a,pair<long long,long long>&b){
        if(a.first==b.first)return a.second<b.second;
        return a.first<b.first;
    }
    long long findScore(vector<int>&v) {
        long long i,n=v.size(),ans=0;
        vector<pair<long long,long long>>vp;
        for(i=0;i<n;i++)vp.push_back({v[i],i});
        sort(vp.begin(),vp.end(),comp);
        vector<int>check(n,0);
        for(i=0;i<n;i++){
            long long x = vp[i].first;
            long long y = vp[i].second;
            if(!check[y]){
                ans+=x;
                check[y]=1;
                if(y-1>=0)check[y-1]=1;
                if(y+1<n)check[y+1]=1;
            }
        }
        return ans;
    }
};
