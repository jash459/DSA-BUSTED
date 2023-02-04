class Solution {
    bool areVectorsEqual(vector<int> a, vector<int> b){
        for(int i=0; i<26; i++){
            if(a[i]!=b[i]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) return false;
        vector<int> freq_S1(26, 0);
        for(char c: s1) freq_S1[c-'a']++;
        
        vector<int> freq_S2(26, 0);
        int i=0, j=0;
        
        while(j<s2.size()){
            freq_S2[s2[j]-'a']++;
            
            if(j-i+1==s1.size()){
                if(areVectorsEqual(freq_S1, freq_S2)) return true;
            }
            
            if(j-i+1<s1.size()) j++;
            else{
                freq_S2[s2[i]-'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};