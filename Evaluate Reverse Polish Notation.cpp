class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int> str;
        
        for(int i=0;i<tokens.size();i++){
            if(tokens[i] == "/" || tokens[i] == "*" || tokens[i] == "+" || tokens[i] == "-"){ 
                int b = str.top();
                str.pop();
                int a = str.top();
                str.pop();
                
                if(tokens[i] == "/")    str.push((long long int)a/b);
                if(tokens[i] == "*")    str.push((long long int)a*b);        
                if(tokens[i] == "+")    str.push((long long int)a+b);
                if(tokens[i] == "-")    str.push((long long int)a-b);
            }
            else str.push(stoi(tokens[i]));
        }
        return str.top();
    }
};
