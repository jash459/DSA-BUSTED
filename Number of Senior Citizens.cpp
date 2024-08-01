class Solution {
private:
    int calculateAge(string s){
        return (s[11] - '0') * 10 + (s[12] - '0');
    }
public:
    int countSeniors(vector<string>& details) {
        // 0 - 9 : phoneNumber
        // 10 : Gender
        // 11 - 12 : Age
        // 13 - 14 : Seat
        // First details string : <PHONE_NUMBER><GENDER>75<SEAT>
        // s[11] : '7' - '0' : 55 - 48 : 7
        // s[12] : '5' - '0  : 53 - 48 : 5
        int cnt = 0;
        for(auto &detail : details) cnt += (calculateAge(detail) > 60);
        return cnt;
    }
};
