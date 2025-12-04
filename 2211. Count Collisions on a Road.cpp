class Solution {
public:
    static int countCollisions(string& D) {
        int n=D.size();
        if (n==1) return 0;
        int l=0, r=n-1;
        while (D[l]=='L') l++;
        while (l<r && D[r]=='R') r--;
        if (l>=r) return 0;
        return count_if(D.begin()+l, D.begin()+(r+1), 
        [](char c){ return c!='S';});      
    }
};
