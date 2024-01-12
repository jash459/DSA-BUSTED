
class Solution {
public:
    bool halvesAreAlike(std::string s) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int vowels_Count = 0;
        int midIndex = s.length() / 2;

        for (int i = 0; i < midIndex; i++) {
            char charA = s[i];
            char charB = s[midIndex + i];
            if (vowels.count(charA)) vowels_Count++;
            if (vowels.count(charB)) vowels_Count--;
        }

        return vowels_Count == 0;
    }
};

