class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char>st(brokenLetters.begin(),brokenLetters.end());
        stringstream ss(text);
        string s;
        int ans=0;
        while(ss>>s){
            bool find =true;
            for(auto it:s){
                if(st.find(it)!=st.end()){
                find=false;
                break;
                }
            }
            if(find)ans++;
        }
        return ans;
    }
};
