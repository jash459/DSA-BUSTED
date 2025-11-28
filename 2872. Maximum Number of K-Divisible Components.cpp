class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<long long> sum(n);
for(int i = 0; i < n; i ++){
    sum[i] = values[i];
}
int ans = 0;
while(!S.empty()){
    int u = S.top();
    S.pop();
    if(sum[u] % k == 0){
        ans += 1;
    }
    else{
        sum[parent[u]] += sum[u];
    }
}
    }
};
