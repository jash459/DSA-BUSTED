class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> U(n);
        for (int i = 0; i < n; ++i)
            U[i] = i * 2 - n + 1;
        return U;
    }
};
