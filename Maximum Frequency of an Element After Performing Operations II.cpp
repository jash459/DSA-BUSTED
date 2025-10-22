class Solution {
public:
    static int maxFrequency(vector<int>& nums, int k, int numOperations) {
        const int n=nums.size();
        auto [mm, MM]=minmax_element(nums.begin(), nums.end());
        unordered_map<int, int> freq, sweep;
        int* values=(int*)alloca(n*12);
        freq.reserve(n);
        sweep.reserve(2*n);
        int i=0;
        for(int x: nums){
            const int x0=max(*mm, x-k), xN=min(*MM+1, x+k+1);
            freq[x]++;
            sweep[x0]++;
            sweep[xN]--;
            values[i++]=x, values[i++]=x0, values[i++]=xN;
        }
        sort(values, values+i);
        int ans=0, cnt=0, prev=-1;
        for(int i=0; i<3*n; i++){
            const int v=values[i];
            if (prev==v) continue;
            auto it=sweep.find(v);
            if (it!=sweep.end()) cnt+=it->second;
            const int f=((it=freq.find(v))!=freq.end())?it->second:0;
            ans=max(ans, f+min(cnt-f, numOperations));
            prev=v;
        }
        return ans;
        
    }
};
