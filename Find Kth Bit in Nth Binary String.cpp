class Solution {
private:
    string revInv(string prevStr)
    {
        string str = prevStr ;
        for(char &ch : str){
            ch = (ch == '0') ? '1' : '0' ;
        }
        reverse(str.begin(), str.end());
        return str ;
    }
    string findStr(int n)
    {
        if(n==1) return "0";
        string prevStr = findStr(n-1);
        return prevStr + "1" + revInv(prevStr);
    }
public:
    char findKthBit(int n, int k) {
        string s = findStr(n);
        return s[k-1];
    }
};
