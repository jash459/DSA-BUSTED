class Solution {
public:
    int minSteps(string s, string t) {
        int count[26] = {0};
        int i = 0;

        // Storing the difference of frequencies of characters in t and s.
        while (i < s.size()) {
            count[t[i] - 'a']++;
            count[s[i] - 'a']--;
            i++;
        }

        int result = 0;
        i = 0;

        while (i < 26) {
            result += max(0, count[i]);
            i++;
        }

        return result;
    }
}; 


