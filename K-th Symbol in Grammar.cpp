#pragma GCC optimize("O3")
class Solution {
public:
    int kthGrammar(int n, int k) {
        if (k==1) return 0;  // Base case

        int bL=31-__builtin_clz(k); //Calculate log2(k)
        if (k==1<<bL) return bL&1;
        //invert the symbol 
        else return 1-kthGrammar(n, k-(1<<bL));   
    }
};
