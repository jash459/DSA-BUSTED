class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str2 + str1 ==  str1 + str2 ){
            return str1.substr(0, gcd(str1.length(), str2.length()));
        }
        return "";
    }
};