class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> first;
        unordered_map<string, int> second;
        
        istringstream in(s); 
        string word;
        int i = 0, n = pattern.size();

        
        for(word; in>>word; i++){
            if(i==n || first[pattern[i]] != second[word]) return false; //If it reaches end before all the words in string 's' are traversed || if values of keys : pattern[i] & word don't match return false
            
            first[pattern[i]] = second[word] = i+1; //Otherwise map to both to a value i+1
        }
        return i==n; //both the lengths should be equal
    }
};