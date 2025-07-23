class Solution {
public:
    static inline int f(string& s, char* X, int x){
        int n=s.size(), sz=0;
        for(int i=0; i<n; i++){
            s[sz++]=s[i];
            if (sz>=2 && s[sz-2]==X[0] && s[sz-1]==X[1]) 
                sz-=2;
        }
        s.resize(sz);
        return (n-sz)/2*x;
    }

    static int maximumGain(string& s, int x, int y) {
        char X[3]="ab", Y[3]="ba";
        if (x<y){// may assume more "ab" than "ba" WLOG
            swap(X, Y);
            swap(x, y);
        }
        
        return f(s, X, x)+f(s, Y, y);
    }
};



auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
