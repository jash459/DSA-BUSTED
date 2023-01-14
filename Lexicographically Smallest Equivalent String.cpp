class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        char chr[26];
        for (int i=0; i<26; i++)
            chr[i] = 'a' + i;

        for (int i=0; i<s1.size(); i++) {
            char toReplace = max(chr[s1[i]-'a'], chr[s2[i]-'a']);
            char replaceWith = min(chr[s1[i]-'a'], chr[s2[i]-'a']);
            for (int i=0; i<26; i++)
                if (chr[i] == toReplace)
                    chr[i] = replaceWith;
        }
        
        for (int i = 0; i<baseStr.size(); i++)
            baseStr[i] = chr[baseStr[i]-'a'];

        return baseStr;
    }
};