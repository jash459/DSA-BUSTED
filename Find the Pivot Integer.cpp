class Solution {
private:
    inline int getSum(int n){
        return (n*(n+1))/2;
    }
public:
    int pivotInteger(int n) {
        int sum = getSum(n);
        for(int i=1; i<=n; ++i){
            int first = getSum(i), second = sum - first + i;
            if(first == second) return i;
        }
        return -1;
    }
};
