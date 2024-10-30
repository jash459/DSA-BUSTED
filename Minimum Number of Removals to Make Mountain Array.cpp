class Solution {
public:
    int minimumMountainRemovals(vector<int>& v) {
        int n = v.size(),i,x;
        vector<int> l(n,0),r(n,0),s;
        s.push_back(v[0]);
        for(i = 1; i < n; i++){
            x = lower_bound(s.begin(),s.end(),v[i])-s.begin();
            if(x==s.size()){
                s.push_back(v[i]);
            }else{
                s[x] = v[i];
            }
            l[i] = i+1-s.size();
        }
        s.clear();
        s.push_back(v[n-1]);
        for(i = n-2; i >= 0; i--){
            x = lower_bound(s.begin(),s.end(),v[i])-s.begin();
            if(x==s.size()){
                s.push_back(v[i]);
            }else{
                s[x] = v[i];
            }
            r[i] = n-1-i+1-s.size();
        }
        int ans = n;
        for(i = 0; i < n; i++){
            if(i+1-l[i]>=2 && n-i-r[i]>=2)
                ans = min(ans,l[i]+r[i]);
        }
        // return ans;
    }
};
