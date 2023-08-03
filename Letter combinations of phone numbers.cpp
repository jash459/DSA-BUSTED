class Solution {
public:
    void solve(int index,string digits, string mapping[],string output, vector<string> &ans){
        if(index >= digits.size()){
            ans.push_back(output);
            return;
        }

        int number=digits[index]-'0';
        string value=mapping[number];

        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            solve(index+1,digits,mapping,output,ans);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if(digits.length()==0) return ans;
    string output="";
    string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(0,digits,mapping,output,ans);
    return ans;
    }
};