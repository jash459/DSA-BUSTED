class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k)
            return false;
        if (s.length() == k)
            return true;

        int odd = 0;

        for (char chr : s)
            odd ^= (1 << (chr - 'a'));

        return __builtin_popcount(odd) <= k;
    }
};
