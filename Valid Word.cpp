class Solution {
public:
    bool isValid(string word) {
        if(word.length() < 3)
            return false;
        bool hasVowel = false, hasConsonant = false;
        for(char c: word){
            if(isalpha(c)){
                c = tolower(c);
                if(c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u')
                    hasVowel = true;
                else
                    hasConsonant = true;
            }
            else if(!isdigit(c))
                return false;         
        }
        return hasVowel and hasConsonant;
    }
};
