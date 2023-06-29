//Solution 01:
class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size(), lowercase = 0, uppercase = 0;
        
        if(n == 1) return true;
        
				bool temp = 0;
        if(word[0]>= 'A' && word[0]<= 'Z') temp = 1;

        for(int i=1; i<n; i++){
            if(word[i]>= 'A' && word[i]<= 'Z'){
                uppercase++;
                if(temp == 0 || lowercase > 0) return 0;
            } 
            else{
                if(uppercase>0) return 0;
                lowercase++;
            } 
        }
        return 1;
    }
};