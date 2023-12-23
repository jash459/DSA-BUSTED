int countOccurence(int a[], int n, int k) {
        // Your code here
        unordered_map<int, int> m;
        for(int i=0; i<n; i++){
            m[a[i]]++;
        }
        int r = n/k;
        int ans=0;
        for(auto it:m){
            if(it.second > r) ans++;
        }
        return ans;
    }