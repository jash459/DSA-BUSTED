class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> freqS(200, 0);
        vector<int> freqT(200, 0); 
        
        int len = s.length(); 
        
        if(len != t.length()) { 
            return false;
        }
        
        for(int i = 0; i < len; i++) { 
            if(freqS[s[i]] != freqT[t[i]]) { 
                return false; 
            }
            
            freqS[s[i]] = i + 1; 
            freqT[t[i]] = i + 1;
        }

        return true; 
    }
};
