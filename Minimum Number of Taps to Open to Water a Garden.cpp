class Solution {
public:
    using int2 = pair<int, int>;

    int minTaps(int n, vector<int>& ranges) {
        vector<int2> I(n+1);
        for (int i=0;  i<=n; i++) {
            int d = ranges[i];
            I[i] = {i-d, i+d};
        }
        sort(I.begin(), I.end());//Sort with left end

        int taps=1;
        int i0=0, a =INT_MIN, b= 0;
        
        // Find the initial interval that covers 0 the most
        while (a <= 0 && i0 <= n) {
            a = I[i0].first;
            if (a <= 0) b = max(b, I[i0].second);
            i0++;
        }

        if (b >= n) return taps;  // Garden is already covered
        
        for (int i=i0; b<n; ) {
            int bMax = b;
            while (i <= n && I[i].first <= b) {
                bMax = max(bMax, I[i].second);
                i++;
            }
            
            if (bMax==b) 
                return -1;  // A gap
            
            b = bMax;  // Update b
            taps++;  // open a tap
        }

        return taps;
    }
};
